//pthread_cancel函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	//设置一下不允许被取消
	//pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	//设置允许被取消
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	//设置立即取消
	//pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
	//设置推迟取消
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
	while(1)
	{
		printf("I am superman!\n");
		//usleep(100000);
	}
}

void* task2(void* p)
{
	printf("开始取消线程一...\n");
	usleep(200000);
	printf("成功取消线程一\n");
	pthread_cancel(*(pthread_t*)p);
}

int main(void)
{
	pthread_t tid,tid2;
	pthread_create(&tid,NULL,task,NULL);
	pthread_create(&tid2,NULL,task2,&tid);
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
