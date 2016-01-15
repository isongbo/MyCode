//使用共享内存进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shmid;

void fa(int signo)
{
	//6.删除共享内存
	int res = shmctl(shmid,IPC_RMID,NULL);
	if(-1 == res)
	{
		perror("shmctl"),exit(-1);
	}
	printf("删除共享内存成功\n");
	exit(0);//终止进程
}

int main(void)
{
	//1.获取key值
	// 路径和项目id相同时,生成的key值也相同
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取共享内存的ID
	shmid = shmget(key,0,0);
	if(-1 == shmid)
	{
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);
	//3.挂接共享内存
	void* p = shmat(shmid,NULL,0);
	if((void*)-1 == p)
	{
		perror("shmat"),exit(-1);
	}
	printf("挂接成功\n");
	//4.使用共享内存
	int* pi = p;
	printf("*pi = %d\n",*pi);
	//5.脱接共享内存
	int res = shmdt(p);
	if(-1 == res)
	{
		perror("shmdt"),exit(-1);
	}
	printf("脱接成功\n");
	
	signal(2,fa);
	printf("删除共享内存，请按ctrl+c\n");
	while(1);
	//练习：发送信号2时，再删除共享内存，否则进程进入无限循环

	return 0;
}


