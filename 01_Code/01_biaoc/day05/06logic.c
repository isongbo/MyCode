/*
   逻辑表达式演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	1 || ++num;
	printf("num是%d\n", num);
	0 && ++num;
	printf("num是%d\n", num);
	return 0;
}
