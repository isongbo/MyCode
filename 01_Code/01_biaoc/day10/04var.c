/*
   变量演示
   */
#include <stdio.h>
int num;
void func(void) {
	int num2 = 0;
	printf("num是%d\n", num);
	//printf("num1是%d\n", num1);
	printf("num2是%d\n", num2);
}
int main() {
	int num1 = 0;
	printf("num是%d\n", num);
	printf("num1是%d\n", num1);
	//printf("num2是%d\n", num2);
	{
		int num3 = 0;
		printf("num3是%d\n", num3);
	}
	//printf("num3是%d\n", num3);
	func();
	return 0;
}
