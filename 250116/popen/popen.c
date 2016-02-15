#include<stdio.h>
int main()
{
	FILE* fp = popen("file.txt","r");
	char buf[512] = {0};
	while(fgets(buf,sizeof(buf),fp))
	{
		puts(buf);
	}
//	printf("buf = %s\n",buf);
	pclose(fp);
	return 0;
}
