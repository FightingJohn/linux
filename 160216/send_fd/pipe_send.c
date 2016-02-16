#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		printf("error args\n");
		return -1;
	}
	int fds[3];
	pipe(fds);//管道
	if(!fork())
	{
		close(fds[1]);//关闭写
		int fd;
		read(fds[0],&fd,4);
		printf("I am child,fd is %d\n",fd);
		char buf[10]={0};
		int ret;
		ret=read(fd,buf,sizeof(buf));
		if(-1==ret)
		{
			perror("read");
			return -1;
		}
		printf("buf is %s\n",buf);
		exit(0);
	}else{
		close(fds[0]);//关闭读
		int fd=open(argv[1],O_RDWR);
		if(-1==fd)
		{
			perror("open");
			return -1;
		}
		printf("I am parent,fd is %d\n",fd);
		write(fds[1],&fd,4);
		wait(NULL);
		exit(0);
	}

}
