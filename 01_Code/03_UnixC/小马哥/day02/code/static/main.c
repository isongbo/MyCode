//调用自定义函数
#include <stdio.h>
//#include "../01add.h"
#include "01add.h"

int main(void)
{
		int resInt = addInt(20,30);
		double resDouble = addDouble(3.14,2.5);
		printf("resInt = %d,resDouble = %lf\n",resInt,resDouble);
		return 0;
}
