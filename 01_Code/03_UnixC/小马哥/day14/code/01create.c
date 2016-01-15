//线程的创建
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* task(void* p)
{
	while(1)
	{
		printf("我是创建出来的线程\n");
	}
}

int main(void)
{
	printf("线程开始创建...\n");
	//创建一个新的线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	usleep(100000);
	return 0;
}
