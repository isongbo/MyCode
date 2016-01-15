/*
   函数练习
   */
#include <stdio.h>
int add(int num, int num1) {
	return num + num1;
}
int main() {
    int num = add(3, 7);
	printf("num是%d\n", num);
	return 0;
}
