//字节序的问题
#include <stdio.h>
#include <stdlib.h>

//定义一个联合的数据类型
union Un
{
	int x;
	char buf[4];
};

int main(void)
{
	union Un un;
	un.x = 0x12345678;
	int i = 0;
	//小端系统：低位地址存放低位数据
	for(i = 0; i < 4; i++)
	{
		printf("%#x[%p] ",un.buf[i],&un.buf[i]);
	}
	printf("\n");
	return 0;
}



