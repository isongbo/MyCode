//预处理指令的使用
#include <stdio.h>
#define GO goto
//设置goto为毒药
#pragma GCC poison goto

int main(void)
{
		//表示跳转到ok那里继续执行
		GO ok;
		printf("大家好才是真是的好\n");
ok:
		printf("执行goto了\n");
		return 0;
}
