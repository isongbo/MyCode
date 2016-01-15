//使用信号量集进行通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{
	//1.获取key值
	key_t key = ftok(".",150);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取信号量集的ID
	int semid = semget(key,0,0);
	if(-1 == semid)
	{
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3.使用信号量集来控制进程数
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		pid_t pid = fork();
		if(0 == pid) //子进程
		{
			//准备结构体
			struct sembuf buf;
			buf.sem_num = 0;//下标
			buf.sem_op = -1;//计数减1
			buf.sem_flg = 0;//操作标志
			//使用semop函数操作信号量
			int res = semop(semid,&buf,1);
			if(-1 == res)
			{
				perror("semop"),exit(-1);
			}
			printf("申请共享资源成功\n");
			sleep(20);
			printf("使用资源完毕\n");
			buf.sem_op = 1;
			semop(semid,&buf,1);
			exit(0);//终止子进程
		}
	}
	return 0;
}






