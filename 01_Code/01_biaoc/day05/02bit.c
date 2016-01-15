/*
   二进制作业
   */
#include <stdio.h>
int main() {
	int num = 0, two = 2;
	printf("请输入一个数字：");
	scanf("%d", &num);
	printf("%9d\r", num - num / two * two);
	num = num / two;
	printf("%8d\r", num - num / two * two);
	num = num / two;
	printf("%7d\r", num - num / two * two);
	num = num / two;
	printf("%6d\r", num - num / two * two);
	num = num / two;
	printf("%4d\r", num - num / two * two);
	num = num / two;
	printf("%3d\r", num - num / two * two);
	num = num / two;
	printf("%2d\r", num - num / two * two);
	num = num / two;
	printf("%d\n", num - num / two * two);
	num = num / two;
	return 0;
}
