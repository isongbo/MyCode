//共享内存的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	//1.获取key值
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);

	//2.根据key值获取共享内存的id
	int shmid = shmget(key,0,0);
	if(-1 == shmid)
	{
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);

	//3.进行挂接
	void* p = shmat(shmid,0,0);
	if(p == (void*)-1)
	{
		perror("shmat"),exit(-1);
	}
	//4.使用
	int* pi = p;
	printf("*pi = %d\n",*pi);

	//5.进行脱接
	shmdt(p);

	//6.删除共享内存
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
