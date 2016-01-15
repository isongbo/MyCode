//预处理指令的使用
#include <stdio.h>
#define VERSION 2
#if(VERSION < 3)
	#error "版本过低"
#elif(VERSION >= 3)
	#warning "版本过高"
#endif

int main(void)
{
		printf("good good study,day day up!\n");
		return 0;
}
