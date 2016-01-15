/*
   函数调用演示
   */
#include <stdio.h>
void print(void) {
	int num = 0;
	printf("1\n");
}
int calc(void) {
	return 2 + 4;
}
int main() {
	int num = 0;
	print();
	num = calc();
	printf("num是%d\n", num);
	return 0;
}



