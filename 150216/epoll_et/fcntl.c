#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
void change_nonblock(int* fd)
{
	int status;
	status=fcntl(*fd,F_GETFL);
	status=status|O_NONBLOCK;
	int ret;
	ret=fcntl(*fd,F_SETFL,status);
	if(0!=ret)
	{
		perror("fcntl");
		return;
	}
}

int main()
{
	char buf[10]={0};
	int ret;
	int fd=0;
	sleep(3);
	change_nonblock(&fd);
	ret=read(fd,buf,sizeof(buf));
	printf("ret is %d\n",ret);
	printf("errno is %d\n",errno);
	printf("buf is %s\n",buf);
	return 0;
}

