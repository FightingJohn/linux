#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	printf("parent process id:%d\n",getpid());
	pid_t iRet = fork();
	if(iRet < 0){//出错
		printf("create child process fail\n");
	}else if(iRet == 0){//表示子进程
		printf("child process id:%d ppid:%d\n",getpid(),getppid());
	}else{//表示父进程
		printf("prarent process success,child id:%d\n",iRet);
	}
	return 0;
}
