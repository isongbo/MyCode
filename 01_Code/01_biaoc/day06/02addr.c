/*
   地址操作符演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("&num是%p\n", &num);
	*(&num) = 10;
	printf("num是%d\n", num);
	return 0;
}
