/*
   函数指针演示
   */
#include <stdio.h>
int add(int num, int num1) {
	return num + num1;
}
int main() {
	int (*p_func)(int, int) = NULL;  //函数指针声明
	p_func = add;
	printf("p_func(3, 8)是%d\n", p_func(3, 8));
	printf("add是%p\n", add);
	return 0;
}
