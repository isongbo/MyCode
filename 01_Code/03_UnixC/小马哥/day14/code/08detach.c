//pthread_detach函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int i = 0;
	for(i = 0; i < 20; i++)
	{
		printf("i = %d\n",i);
		usleep(200000);
	}
}

int main(void)
{
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//分离子线程
	pthread_detach(tid);
	// pthread_detach 使得pthread_join无法等待
	pthread_join(tid,NULL);
	int i = 0;
	for(i = 0; i < 20; i++)
	{
		printf("main: i = %d\n",i);
		usleep(100000);
	}
	return 0;
}



