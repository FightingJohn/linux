#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void sig(int signum)
{
	printf("the signum is %d\n",signum);
	sleep(3);
	printf("after sleep,the signum is %d\n",signum);
}

int main()
{
	signal(SIGINT,sig);
	int ret;
	char buf[10]={0};
	ret=read(0,buf,sizeof(buf));		
	printf("buf is %s\n",buf);
	return 0;
}
