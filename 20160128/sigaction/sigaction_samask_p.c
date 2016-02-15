#include <stdio.h>
#include <signal.h>
#include <strings.h>
#include <stdlib.h>
void siga(int signum,siginfo_t *p,void* p1)//信号处理函数
{
	printf("I get the sig %d\n",signum);
	sleep(5);
	sigset_t set;
	sigemptyset(&set);
	int ret;
	ret=sigpending(&set);//获取被阻塞的信号
	if(-1==ret)
	{
		perror("sigpending");
		return;
	}
	if(1==sigismember(&set,SIGINT))
	{
		printf("the SIGINT is pending\n");
	}	
	if(1==sigismember(&set,SIGQUIT))
	{
		printf("the SIGQUIT is pending\n");
	}	
	printf("after sleep,sig is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction = siga;
	sigset_t sa_mask;
	sigemptyset(&act.sa_mask);
	//memcpy(&act.sa_mask,&sa_mask,sizeof(sa_mask));
	int ret;
	ret=sigfillset(&act.sa_mask);
	if(-1==ret)
	{
		perror("sigaddset");
		return -1;
	}
	act.sa_flags=SA_SIGINFO|SA_NODEFER;	
	ret=sigaction(SIGINT,&act,NULL);//设置信号处理行为
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}
	while(1);
	return 0;
}
	


