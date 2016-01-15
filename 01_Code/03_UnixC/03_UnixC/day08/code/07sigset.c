//信号集的概念和使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	sigset_t set;
	printf("sizeof(sigset_t) = %d\n",sizeof(sigset_t));
	//sigset_t本质是结构体类型，假定为long int
	printf("set = %ld\n",set);
	
	printf("--------------------\n");
	//清空信号集
	int res = sigemptyset(&set);
	if(-1 == res)
	{
		perror("sigemptyset"),exit(-1);
	}
	printf("set = %ld\n",set);

	printf("---------------------\n");
	//增加信号到信号集中
	res = sigaddset(&set,2);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %ld\n",set);//2

	res = sigaddset(&set,3);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %ld\n",set);//6 => 2 + 4

	res = sigaddset(&set,6);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %ld\n",set);//38

	//小端系统：表示低位字节存储低位数据
	//大端系统：表示低位字节存储高位数据
	// 0x12345678
	// 小端系统：0x78 0x56 0x34 0x12
	// 大端系统：0x12 0x34 0x56 0x78
	
	printf("-----------------------\n");
	//删除信号集中的信号
	res = sigdelset(&set,3);
	if(-1 == res)
	{
		perror("sigdelset"),exit(-1);
	}
	printf("set = %ld\n",set); //34

	printf("----------------------\n");
	if(sigismember(&set,3))
	{
		printf("信号3存在\n");
	}
	if(sigismember(&set,6))
	{
		printf("信号6存在\n");
	}

	printf("---------------------\n");
	sigfillset(&set);
	printf("set = %ld\n",set);
	return 0;
}
