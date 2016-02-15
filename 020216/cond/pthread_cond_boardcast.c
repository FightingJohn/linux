#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 5
pthread_cond_t cond;
pthread_mutex_t mutex;

void* p_func(void* p)
{
	pthread_mutex_lock(&mutex);
	int ret;
	int i=(int)p;
	printf("I am child %d,I am here\n",i);
	ret=pthread_cond_wait(&cond,&mutex);
	if(0!=ret)
	{
		printf("pthread_cond_wait ret=%d\n",ret);
	}
	printf("I am child thread %d,I am wake\n",i);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	int ret;
	ret=pthread_cond_init(&cond,NULL);
	if(0!=ret)
	{
		printf("pthread_cond_init ret=%d\n",ret);
		return -1;
	}
	ret=pthread_mutex_init(&mutex,NULL);
	if(0!=ret)
	{
		printf("pthread_mutex_init ret=%d\n",ret);
		return -1;
	}
	pthread_t thid[NUM];
	int i;
	for(i=0;i<NUM;i++)
	{
		pthread_create(&thid[i],NULL,p_func,(void*)i);
	}
	sleep(1);
	pthread_cond_broadcast(&cond);
	for(i=0;i<NUM;i++)
	{
		ret=pthread_join(thid[i],NULL);
		if(0!=ret)
		{
			printf("pthread_join ret=%d\n",ret);
			return -1;
		}
	}
	ret=pthread_cond_destroy(&cond);
	if(0!=ret)
	{
		printf("pthread_cond_destroy ret=%d\n",ret);
		return -1;
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
