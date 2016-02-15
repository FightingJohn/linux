#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("argc error\n");
		return -1;
	}
	int ret;
	//ret=mkdir(argv[1],0705);
	ret=rmdir(argv[1]);
	printf("%d",ret);
	return 0;
}
