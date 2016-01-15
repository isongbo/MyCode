//#pragma的使用
#include <stdio.h>

//表示按照2的整数倍进行对齐和补齐
//#pragma pack(2) //8
//#pragma pack(1) //6
//#pragma pack(0) //无意义
//#pragma pack(3) //错误的用法 char short int float double

int main(void)
{
	struct S
	{
		char c1; //1 2 3 4 ...
		int i;   //4 8 12 ...
		char c2; //1 2 3 4 ...
	};
	printf("sizeof(struct S) = %d\n",sizeof(struct S));
	return 0;
}
