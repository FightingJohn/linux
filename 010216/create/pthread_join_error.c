#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
void* thread_func(void* p)
{
	printf("I am child\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t thid,thid1;
	pthread_create(&thid,NULL,thread_func,NULL);//创建子线程
	int ret=pthread_join(0,NULL);//等待子线程退出
	if(0 !=ret)
	{
		printf("ret is %d\n",ret);
		return -1;
	}
	return 0;
}
