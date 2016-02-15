#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{
	int semid;
	semid=semget((key_t)1234,3,0600|IPC_CREAT);//创建一个信号量集合，里边有3个信号量
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}	
	int ret;
	unsigned short arr[3];//定义一个无符号短整型数组，和信号量数目必须同样大小
	ret=semctl(semid,0,GETALL,arr);//获取所有信号量的值
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("1sem=%d,2sem=%d,3sem=%d\n",arr[0],arr[1],arr[2]);
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	ret=semctl(semid,0,SETALL,arr);//将数组中的值，设置给每一个信号量，依次对应
	if(-1==ret)
	{
		perror("semctl1");
		return -1;
	}
	bzero(arr,sizeof(arr));	
	ret=semctl(semid,0,GETALL,arr);//获取所有信号量的值
	if(-1==ret)
	{
		perror("semctl2");
		return -1;
	}
	printf("1sem=%d,2sem=%d,3sem=%d\n",arr[0],arr[1],arr[2]);
	return 0;
}

