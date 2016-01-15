/*
   函数演示
   */
#include <stdio.h>
double add(double, double);
int main() {
	int num = add(3, 7);
	printf("num是%d\n", num);
	return 0;
}
double add(double num, double num1) {
	return num + num1;
}



