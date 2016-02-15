#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<strings.h>
int main(int argc,char* argv[])
{
	if(argc != 2)
	{
		printf("error args\n");
		return -1;
	}

	int fd;
	fd = open(argv[1], O_RDWR,0600);
	if(-1==fd)
	{
		perror("open");
		printf("errno is %d\n",errno);
		return -1;
	}
	char buf[128];
	bzero(buf,sizeof(buf));
	int ret;
	ret=read(fd,buf,sizeof(buf));
	printf("the ret is %d\n",ret);
	printf("the buf[4] is %d\n",buf[4]);
	printf("the buf is %s\n",buf);
	close(fd);
	return 0;
}
