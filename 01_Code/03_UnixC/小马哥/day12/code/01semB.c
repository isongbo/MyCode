//创建10个进程模拟抢占资源的过程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{
	//1.获取key值
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	//2.获取信号量集的id
	int semid = semget(key,0,0);
	if(-1 == semid)
	{
		perror("semget"),exit(-1);
	}
	//3.模拟抢占共享资源的过程
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		pid_t pid = fork();
		if(-1 == pid)
		{
			perror("fork"),exit(-1);
		}
		if(0 == pid) //子进程
		{
			struct sembuf op;
			op.sem_num = 0;//下标
			op.sem_op = -1;//计数器减1
			op.sem_flg = 0;
			//使用semop函数申请资源
			semop(semid,&op,1/*信号量集大小*/);
			printf("申请共享资源成功\n");
			sleep(20);
			printf("共享资源使用完毕\n");
			//使用semop函数释放资源
			op.sem_op = 1;
			semop(semid,&op,1);
			//结束子进程，防止子进程创建子进程
			exit(0);
		}
	}




	return 0;
}
