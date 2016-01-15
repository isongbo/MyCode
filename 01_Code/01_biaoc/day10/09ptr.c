/*
   指针演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	int *p_num = &num;
	*p_num = 10;
	printf("num是%d\n", num);
	printf("p_num是%p\n", p_num);
	printf("*p_num是%d\n", *p_num);
	return 0;
}
