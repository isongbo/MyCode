//线程的独立和影响
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		printf("新线程中：i = %d\n",i);
	}
}
int main(void)
{
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		printf("主线程中：i = %d\n",i);
	}
	usleep(100000);
	//pthread_t 是 unsigned long int
	printf("子线程的id = %lu\n",tid);
	printf("主线程的id = %lu\n",pthread_self());
	return 0;
}



