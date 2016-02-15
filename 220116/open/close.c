#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc,char* argv[])
{
	if(argc != 2)
	{
		printf("error args\n");
		return -1;
	}

	int fd;
	fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC,0600);
	if(-1==fd)
	{
		perror("open");
		printf("errno is %d\n",errno);
		return -1;
	}
	close(fd);
	return 0;
}
