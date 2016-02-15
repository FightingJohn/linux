#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int semid;
	semid=semget((key_t)1234,1,0600|IPC_CREAT);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	int ret;
	struct semid_ds buf;
	ret=semctl(semid,0,IPC_STAT,&buf);
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("uid=%d,cuid=%d,mode=%u,nsem=%lu\n",buf,sem_p);
	return 0;
}
