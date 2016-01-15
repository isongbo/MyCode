/*
   静态变量演示
   */
#include <stdio.h>
void func(void) {
	static int num = 10;
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
