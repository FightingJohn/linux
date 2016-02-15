#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <strings.h>
pthread_cond_t cond;
pthread_mutex_t mutex;

void* p_func(void* p)
{
	int ret;
	struct timespec ts;
	struct timeval now;
	bzero(&ts,sizeof(ts));
	gettimeofday(&now,NULL);
	ts.tv_sec = now.tv_sec + 5;
	pthread_mutex_lock(&mutex);
	printf("I am child,I am here\n");
	ret=pthread_cond_timedwait(&cond,&mutex,&ts);//超时等待，ret是110
	if(0!=ret)
	{
		printf("pthread_cond_timedwait ret=%d\n",ret);
	}
	printf("I am child thread,I am wake\n");
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
	pthread_t thid;
	pthread_create(&thid,NULL,p_func,NULL);
	sleep(1);
	pthread_cond_signal(&cond);
	ret=pthread_join(thid,NULL);
	if(0!=ret)
	{
		printf("pthread_join ret=%d\n",ret);
		return -1;
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
