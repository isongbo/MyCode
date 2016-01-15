/*
   三目表达式演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("请输入一个整数：");
	scanf("%d", &num);
	num = num >= 0 ? num : 0 - num;
	printf("num是%d\n", num);
	return 0;
}
