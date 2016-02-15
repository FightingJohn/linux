#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int fds[2] = {0};
	pipe(fds);
	char szBuf[32] = {'\0'};
	if(fork()==0)//表示子进程
	{
		close(fds[1]);//子进程关闭
		sleep(2);//确保父进程有时间关闭都，并且往管道中写内容
		if(read(fds[0],szBuf,sizeof(szBuf))>0)
		{
			puts(szBuf);
		}
		close(fds[0]);//子关闭读
		exit(0);
	}else{//父进程
		close(fds[0]);//父关闭读
		write(fds[1],"hello",6);
		waitpid(-1,NULL,0);//等子关闭读
		close(fds[1]);//父关闭写
		exit(0);	
	}
	return 0;
}
