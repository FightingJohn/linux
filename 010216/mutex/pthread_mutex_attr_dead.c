#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define NUM 10000000
pthread_mutex_t mutex;
int sum=0;
void* p_func(void* p)
{
	int ret;
	ret=pthread_mutex_lock(&mutex);
	printf("pthread_mutex_lock1 ret=%d\n",ret);
	ret=pthread_mutex_lock(&mutex);
	if(0!=ret)
	{
		printf("pthread_mutex_lock2 ret=%d\n",ret);
	}
	printf("I am child\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	int ret;
	pthread_mutexattr_t attr;
	int i;
	i=PTHREAD_MUTEX_ERRORCHECK_NP;
	memcpy(&attr,&i,4);
	ret=pthread_mutex_init(&mutex,&attr);	
	if(0!=ret)
	{
		printf("pthread_mutex_init ret=%d\n",ret);
		return -1;
	}
	pthread_t pthid;
	pthread_create(&pthid,NULL,p_func,NULL);
	ret=pthread_join(pthid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret=%d\n",ret);
		return -1;
	}
	ret=pthread_mutex_destroy(&mutex);
	if(0!=ret)
	{
		printf("pthread_mutex_destroy ret=%d\n",ret);
		return -1;
	}
	return 0;
}
