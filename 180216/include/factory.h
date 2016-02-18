#ifndef __FACTORY__
#define __FACTORY__
#include "head.h"
#include "work_que.h"

#define DOWN_FILE "hello.avi"
typedef void* (*pfunc)(void*);
typedef struct thread_pool{
	pthread_cond_t cond;
	pthread_t* pth;
	pfunc entry;
	que_t fd_que;
	int start_flag;//线程是否启动
	int thread_num;
}factory,*pfactory;

typedef struct tdata{
	int len;
	char buf[1000];
}data_t,*pdata_t;

void factory_init(pfactory,int,int,pfunc);
void factory_start(pfactory);
void* thread_handle(void*);
void send_file(int);
void send_n(int,char*,int);
#endif

