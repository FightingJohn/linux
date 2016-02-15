#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
char *p;
void* thread_func(void* p1)
{
	printf("I am child\n");
	p=(char*)malloc(10);	
	free(p);
	//p=NULL;//必须把p置为NULL，因为没有及时回收，所以才可以写
	pthread_exit(NULL);
}

int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,thread_func,NULL);//创建子线程
	int ret=pthread_join(thid,NULL);//等待子线程退出
	if(0 !=ret)
	{
		printf("ret is %d\n",ret);
		return -1;
	}
	strcpy(p,"hello");
	printf("the p is %s\n",p);	
	return 0;
}
