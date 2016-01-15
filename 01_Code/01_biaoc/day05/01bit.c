/*
   二进制作业
   */
#include <stdio.h>
int main() {
	int num = 0, base = 128, two = 2;
	printf("请输入一个数字：");
	scanf("%d", &num);
	printf("转换结果是");
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("%d", num / base);
	num = num - num / base * base;
	base = base / two;
	printf("\n");
	return 0;
}
