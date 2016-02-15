#include <stdio.h>
#include <pthread.h>

void cleanup(void* p)
{
	printf("the p is %d\n",(int)p);
}

void* pthread_func(void *p)
{
	pthread_cleanup_push(cleanup,(void*)1);//释放空间，用于释放指针类型的变量
	pthread_cleanup_push(cleanup,(void*)2);
	sleep(5);
	pthread_cleanup_pop(1);//如果为0,执行到该位置，就是弹出函数不执行清理函数	
	pthread_cleanup_pop(1);	
}

int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,pthread_func,NULL);
	int ret;
	ret=pthread_cancel(pthid);
	if(0!=ret)
	{
		printf("pthread_cancel ret=%d\n",ret);
	}	
	ret=pthread_join(pthid,NULL);
	if(0 != ret)
	{
		printf("pthread_join ret=%d\n",ret);
		return -1;
	}
	return 0;
}
