//进程中的堆区空间在线程中共享
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int* pj = p;
	printf("*pj = %d\n",*pj); //100
}

int main(void)
{
	//1.申请一块堆区内存空间
	int* pi = malloc(sizeof(int));
	*pi = 100;
	//2.启动新的线程访问堆区内存
	pthread_t tid;
	pthread_create(&tid,NULL,task,pi);
	//free(pi);//释放堆区的内存
	//pi = NULL;
	//usleep(100000);
	//3.等待线程的结束
	pthread_join(tid,NULL);



	return 0;
}
