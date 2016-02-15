#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
void sig(int s)
{
	printf("the signum is %d\n",s);
}

int main()
{
	signal(SIGUSR1,sig);//设置2号信号的信号处理行为
	int ret;
	ret=kill(getpid(),SIGUSR1);//向自己发送2号信号
	if(-1==ret)
	{
		perror("kill");
		return -1;
	}
	return 0;
}
