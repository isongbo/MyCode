//pthread_join函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* p)
{
	//int* pi = (int*)p;
	//int* pi = p;  *pi
	//*(int*)p  => *pi
	// pc指向  只读常量区
	// pc本身在 栈区 
	char* pc = "hello";
	return pc; //只读常量区的地址
	//return &pc; //栈区的地址

	//pc指向 栈区   本身也在栈区
	//char pc[10] = "hello";
	//return pc;  不太靠谱的
}

void* task2(void* p)
{
	int i = 0;
	static int sum = 0;
	for(i = 1; i <= 100; i++)
	{
		sum += i;
	}
	return &sum;
}

int main(void)
{
	//1.启动一个新的线程
	pthread_t tid,tid2;
	pthread_create(&tid,NULL,task,NULL);
	//2.等待线程的结束并且接受返回值
	char* ps = NULL;
	pthread_join(tid,(void**)&ps);
	printf("ps = %s\n",ps);

	pthread_create(&tid2,NULL,task2,NULL);
	int* pi = NULL;
	pthread_join(tid2,(void**)&pi);
	printf("*pi = %d\n",*pi);
	return 0;
}



