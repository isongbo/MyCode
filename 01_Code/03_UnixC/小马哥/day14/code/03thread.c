//线程共享进程中的资源
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	// p = &num;
	int* pi = p;
	*pi = 200;
}

int main(void)
{
	int num = 100;
	//创建一个新的线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,&num);
	sleep(1);
	printf("num = %d\n",num);//200
	return 0;
}
