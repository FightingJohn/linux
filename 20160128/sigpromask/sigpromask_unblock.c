#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	sigset_t set;
	sigemptyset(&set);
	int ret;
	ret=sigaddset(&set,SIGINT);
	if(-1==ret)
	{
		perror("sigaddset");
		return -1;
	}
	ret=sigprocmask(SIG_BLOCK,&set,NULL);//全程阻塞2号信号
	if(-1==ret)
	{
		perror("sigprocmask");
		return -1;
	}
	sleep(10);
	ret=sigprocmask(SIG_UNBLOCK,&set,NULL);
	if(-1==ret)
	{
		perror("sigprocmask");
		return -1;
	}
	while(1);
	return 0;
}
