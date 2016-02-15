#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
	typedef void (*sigp)(int);
	sigp p;
	p=signal(SIGINT,SIG_IGN);
	if(SIG_ERR==p)
	{
		perror("signal");
		return -1;
	}
	while(1);
	return 0;
}
