//圆的周长和面积的计算
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	int* pi = p;
	printf("圆的周长是：%lf,面积是：%lf\n",2*3.14*(*pi),3.14*(*pi)*(*pi));
}

int main(void)
{
	int r = 0;
	printf("请输入半径：\n");
	scanf("%d",&r);
	//启动一个新的线程进行计算
	pthread_t tid;
	pthread_create(&tid,NULL,task,&r);
	sleep(1);
	printf("r = %d\n",r);
	return 0;
}
