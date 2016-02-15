#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* pthread_func(void* p)
{
	printf("I am child thread\n");
	while(1);
	pthread_exit(NULL);
}

int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,pthread_func,NULL);
	sleep(3);
	int ret=pthread_cancel(pthid);
	if(0 != ret)
	{
		printf("ret is %d\n",ret);
	}
	return 0;
}
