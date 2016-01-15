//#pragma的使用
#include <stdio.h>

#define GO goto
//设置为毒药
#pragma GCC poison goto
//#pragma GCC poison int

int main(void)
{
	GO ok;
		printf("main函数开始执行\n");
	ok:
		printf("main函数结束\n");
	return 0;
}
