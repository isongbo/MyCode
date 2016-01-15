/*
   const演示
   */
#include <stdio.h>
int main() {
	const int num = 0;
	//num = 10;   错误
	printf("请输入一个数字：");
	scanf("%d", &num);
	printf("num是%d\n", num);
	return 0;
}
