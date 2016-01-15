//pthread_exit函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		if(20 == i)
		{
			//终止当前线程
			pthread_exit((void*)i);
			//return (void*)i;
			//exit(0); 终止整个进程
		}
		printf("i = %d\n",i);
	}
}

int main(void)
{
	//1.启动一个新的线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//2.主线程等待结束
	int num = 0;
	pthread_join(tid,(void**)&num);
	printf("num = %d\n",num);
	return 0;
}


