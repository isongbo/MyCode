/*
   声明周期和作用域演示
   */
#include <stdio.h>
void func(void) {
	int num;
	printf("num是%d\n", num);
	num = 3;
}
void func1(void) {
	int num = 10;
	int num1 = 11;
	int num2 = num + num1;
}
int main() {
	func();
	func1();
	func();
	return 0;
}
