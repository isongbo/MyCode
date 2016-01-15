//信号集的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//定义一个信号集类型的变量
	sigset_t set;
	printf("set = %ld\n",set);
	printf("sizeof(set) = %d\n",sizeof(set));
	
	//清空信号集
	sigemptyset(&set);
	printf("set = %ld\n",set);//0
	//把信号2放入信号集中
	sigaddset(&set,2);
	printf("set = %ld\n",set);//2
	sigaddset(&set,3);
	printf("set = %ld\n",set);//6
	sigaddset(&set,7);
	printf("set = %ld\n",set);//70 
	//删除一个信号
	sigdelset(&set,3);
	printf("set = %d\n",set);//66
	//判断信号3是否存在
	if(sigismember(&set,3))
	{
		printf("信号3存在\n");
	}
	if(sigismember(&set,7))
	{
		printf("信号7存在\n");
	}
	//填满信号集
	sigfillset(&set);
	printf("set = %ld\n",set);
	return 0;
}



