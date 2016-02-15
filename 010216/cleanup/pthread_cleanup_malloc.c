#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void cleanup(void* p)
{
	free(p);
	p=NULL;
	printf("the memory is free\n");	
}

void* pthread_func(void *p1)
{
	char *p=(char*)malloc(10);
	pthread_cleanup_push(cleanup,p);//释放指针p
	sleep(5);
	pthread_exit(NULL);
	pthread_cleanup_pop(1);//如果为0,执行到该位置，就是弹出函数不执行清理函数	
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
