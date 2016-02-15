#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t iRet = fork();
	if(iRet == 0){//表示子进程
		while(1);
	}else{//表示父进程
		exit(10);
	}
	return 0;
}
