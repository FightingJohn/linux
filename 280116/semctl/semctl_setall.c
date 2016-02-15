#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int main()
{
	int semid;
	semid=semget((key_t)1234,10,0600|IPC_CREAT);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	int ret;
	unsigned short arr[3];
	ret=semctl(semid,0,GETALL,arr);//获取所有信号量的值
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("lsem=%d,2sem=%d,3sem=%d\n",arr[0],arr[1],arr[2]);
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	ret=semctl(semid,0,SETALL,arr);//将数组中的值,设置给每一个信号量，依次对应
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	 }
	bzero(arr,sizeof(arr));
	ret=semctl(semid,0,GETALL,arr);
	if(-1==ret)
	{
		perror("semct2");
		return -1;
	}
	printf("lsem=%d,2sem=%d,3sem=%d\n",arr[0],arr[1],arr[2]);
	return 0;

}
