//使用信号量集控制有限资源的访问
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
	printf("开始删除信号量集...\n");
	sleep(2);
	semctl(semid,0/*下标*/,IPC_RMID,NULL);
	//下面的代码虽然好使，尽量少这么用
	//semctl(semid,IPC_RMID/*下标*/,0,NULL);
	//printf("IPC_RMID = %d\n",IPC_RMID);//0
	printf("删除信号量集成功\n");
	exit(0);
}

int main(void)
{
	//1.获取key值
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);

	//2.根据key值创建信号量集
	semid = semget(key,1/*信号量集的大小*/,IPC_CREAT|IPC_EXCL|0666);
	if(-1 == semid)
	{
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3.初始化信号量集
	int res = semctl(semid,0/*数组的下标*/,SETVAL,5/*初始化信号量的最大值*/);
	if(-1 == res)
	{
		perror("semctl"),exit(-1);
	}
	//练习：ctrl+c时，删除信号量集
	signal(SIGINT,fa);
	while(1);
	return 0;
}
