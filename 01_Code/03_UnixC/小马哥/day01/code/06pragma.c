//预处理指令的使用
#include <stdio.h>
//表示按照1的整数倍进行对齐和补齐 6
//#pragma pack(1) //6
#pragma pack(2) //8
//int fn(){} 可以接受任意多个任意类型的实参

int main(void)
{
		//fn(66,3.14,"hello");
		struct/*关键字*/ S/*结构体类型名,整体作为一种数据类型，相当于int*/
		{
				char c1;
				int i;
				char c2;
		};//s; s表示结构体变量名，上面使用typedef则这里变成别名
		printf("sizeof(struct S) = %d\n",sizeof(struct S));
		return 0;
}
