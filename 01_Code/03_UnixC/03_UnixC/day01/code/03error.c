//#error  #warning 的使用
#include <stdio.h>

#define VERSION 3	
#if(VERSION < 3)
	#error "版本过低"
#elif(VERSION >= 3)
	#warning "版本过高"
#endif

int main(void)
{
	printf("我们的口号是：没有蛀牙\n");
	return 0;
}
