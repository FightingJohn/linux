#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* pthread_entry(void* p)
{
//	printf("thread create success\n");
	int i;
	for(i=0;i<10;i++)
	{
		printf("I am child thread %d\n",(int)p);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t pth_id;
	int ret;
	ret=pthread_create(&pth_id,NULL,pthread_entry,(void*)1);//(void*)1表示传递参数值为1
	if(-1==ret)
	{
		perror("pthread_create");
		printf("ret is %d\n",ret);
		return -1;
	}
	int i;
	for(i=0;i<10;i++)
	{
		printf("I am main thread\n");
		sleep(1);
	}
	return 0;
}
