#include<stdlib.h>
#include<sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

#define TIMES 10000000
#define PROJ_ID 1

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    key_t skey;
    skey=ftok(argv[1],PROJ_ID);//创建一个可以被多个进程共享的信号量
    if(-1==skey)
    {
        perror("ftok");
        return -1;
    }
    printf("the key is %d\n",skey);
    int shmid;
    shmid=shmget(skey,1<<12,0600|IPC_CREAT);//创建一个信号量集或者访问一个已经存在的信号量集
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	printf("the shmid is %d\n",shmid);
	int *p;
	p=(int*)shmat(shmid,NULL,0);//将共享内存段映射到进程空间的某一地址
	if((int*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	int i;
	for(i=0;i<TIMES;i++)
	{
		*p=(*p)+1;
	}
	printf("the value is %d\n",*p);
	return 0;
}
