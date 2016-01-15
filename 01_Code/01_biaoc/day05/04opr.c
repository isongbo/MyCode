/*
   操作符演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	char ch = 0;
	printf("15 %% 6是%d\n", 15 % 6);
	num = (4 + 2, 7 - 6);
	printf("num是%d\n", num);
	num = ch = 300;
	printf("ch是%hhd,num是%d\n", ch, num);
	num = 10;
	num += 5;
	printf("num是%d\n", num);
	num *= 2 + 3;
	printf("num是%d\n", num);
	return 0;
}



