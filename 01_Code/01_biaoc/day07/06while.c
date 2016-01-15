/*
   while循环演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	while (num >= 0) {
		printf("请输入一个数字：");
		scanf("%d", &num);
	}
	return 0;
}
