/*
   变量练习
   */
#include <stdio.h>
int main() {
	int num = 1, num1 = 2, ten = 10;
	printf("%d\n", num);
	num = ten * num + num1;
	printf("%d\n", num);
	num1++;
	num = ten * num + num1;
	printf("%d\n", num);
	num1++;
	num = ten * num + num1;
	printf("%d\n", num);
	num1++;
	num = ten * num + num1;
	printf("%d\n", num);
	return 0;
}
