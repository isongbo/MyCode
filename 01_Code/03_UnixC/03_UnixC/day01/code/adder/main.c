#include <stdio.h>
#include "adder.h"
//#include "../adder.h"

int main(void)
{
	printf("两个整数的和是：%d\n",add_int(10,20));
	printf("两个浮点数的和是：%lf\n",add_double(3.14,3.14));
	return 0;
}
