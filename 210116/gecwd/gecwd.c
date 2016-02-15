#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>

int main(int argc,char* argv[])
{

	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	char buf[50];
	bzero(buf,sizeof(buf));
	chdir(argv[1]);//将当前的工作目录改为参数所指向的工作目录
	printf("the path is %s\n",getcwd(buf,sizeof(buf)));
	printf("the buf is %s\n",buf);
	return 0;
}
