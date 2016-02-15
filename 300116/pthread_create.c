#include<stdio.h>
#include<pthread.h>

void* pthread_entry(void* p)
{
	printf("thread create success\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t pth_id;
	int ret;
	ret=pthread_create(&pth_id,NULL,pthread_entry,NULL);//创建线程
	if(-1==ret)
	{
		perror("pthread_create");
		printf("ret is %d\n",ret);
		return -1;
	}
	while(1);
	return 0;
}
