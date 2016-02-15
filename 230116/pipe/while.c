#include <stdio.h>
#include <unistd.h>
#include <strings.h>
int main()
{
	sleep(5);
	char buf[128];
	bzero(buf,sizeof(buf));	
	int ret;
	ret=read(STDIN_FILENO,buf,sizeof(buf));
	if(ret >0)
	{
		printf("the buf is %s\n",buf);
	}
	return 0;
}

