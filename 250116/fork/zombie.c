#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t iRet = fork();
	if(iRet == 0){//表示子进程
		printf("child process id:%d ppid:%d\n",getpid(),getppid());
		exit(10);
	}else{//表示父进程
		printf("prarent process success,child id:%d\n",iRet);
		sleep(10);
	}
	return 0;
}
