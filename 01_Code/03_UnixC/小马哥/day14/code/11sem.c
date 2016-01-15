//使用信号量解决线程的同步问题
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

//准备共享资源
char* buf[5]; 
//表示数组的下标
int pos;
//1.定义互斥量
//pthread_mutex_t lock;
//1.定义信号量
sem_t sem;

//自定义线程处理函数
void* task(void* p)
{
	//3.进行加锁
	//pthread_mutex_lock(&lock);
	//3.获取信号量
	sem_wait(&sem);

	buf[pos] = p;
	sleep(1);
	pos++;
	//4.进行解锁
	//pthread_mutex_unlock(&lock);
	//4.释放信号量
	sem_post(&sem);
}

int main(void)
{
	//2.初始化互斥量
	//pthread_mutex_init(&lock,0);
	//2.初始化信号量
	sem_init(&sem,0,1/*效果等同于互斥量*/);
	
	pthread_t tid,tid2;
	pthread_create(&tid,NULL,task,"zhangfei");
	pthread_create(&tid2,NULL,task,"guanyu");
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	//5.销毁互斥量
	//pthread_mutex_destroy(&lock);
	//5.销毁信号量
	sem_destroy(&sem);

	int i = 0;
	for(i = 0; i < pos; i++)
	{
		printf("%s ",buf[i]);
	}
	printf("\n");
	return 0;
}
