#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("argc error\n");
		return -1;
	}
	int ret;
	ret=chmod(argv[1],0705);
	if(-1==ret)
	{
		perror("chmod1");
		return -1;
	}
	printf("%d",ret);
	return 0;
}
