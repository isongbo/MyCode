//使用共享内存进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	//1.获取key值，使用ftok函数
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.创建/获取共享内存,使用shmget函数
	int shmid = shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
	if(-1 == shmid)
	{
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);
	//3.挂接共享内存,使用shmat函数
	void* p = shmat(shmid,NULL,0);
	if((void*)-1 == p)
	{
		perror("shmat"),exit(-1);
	}
	printf("挂接共享内存成功\n");
	//4.使用共享内存
	int* pi = p;
	*pi = 118;
	//5.脱接共享内存,使用shmdt函数
	int res = shmdt(p);
	if(-1 == res)
	{
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");
	return 0;
}
