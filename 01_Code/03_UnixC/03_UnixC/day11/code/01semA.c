//使用信号量集进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>

int semid;

void fa(int signo)
{
	printf("正在删除信号量集，请稍后...\n");
	sleep(3);
	int res = semctl(semid,0,IPC_RMID);
	if(-1 == res)
	{
		perror("semctl"),exit(-1);
	}
	printf("删除信号量集成功\n");
	exit(0);//终止进程
}

int main(void)
{
	//1.获取key值,使用ftok函数
	key_t key = ftok(".",150);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.创建信号量集，使用semget函数
	semid = semget(key,1/*信号量集的大小*/,IPC_CREAT|IPC_EXCL|0666);
	if(-1 == semid)
	{
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3.初始化信号量集,使用semctl函数
	int res = semctl(semid,0/*信号量集的下标*/,SETVAL,5/*计数器的初始值为5*/);
	if(-1 == res)
	{
		perror("semctl"),exit(-1);
	}
	printf("信号量集初始化成功\n");
	//4.使用信号来删除信号量集
	printf("删除信号量集，请按ctrl+c...\n");
	signal(SIGINT,fa);
	while(1);
	return 0;
}



