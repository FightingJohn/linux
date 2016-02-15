#include<time.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<pwd.h>
#include<grp.h>
#include<dirent.h>
int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	struct stat st1;
	DIR *dp=opendir(argv[1]);
	struct dirent *pt;
	pt=readdir(dp);
	
	int ret;
	ret=stat(argv[1],&st1);
	if(-1==ret)
	{
		perror("stat");
		return -1;
	}
	printf("%6x%3d%5s%5s%5ld%25s%5s\n",st1.st_mode,st1.st_nlink,getpwuid(st1.st_uid)->pw_name,getgrgid(st1.st_gid)->gr_name,st1.st_size,ctime(&st1.st_mtime),pt->d_name);
	return 0;
}
