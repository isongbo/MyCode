/*
   位操作符演示
   */
#include <stdio.h>
int main() {
	int num = ~0xabcdef12;
	printf("num是0x%x\n", num);
	printf("3 & 5是%d\n", 3 & 5);
	printf("3 | 5是%d\n", 3 | 5);
	printf("3 ^ 5是%d\n", 3 ^ 5);
	printf("12 >> 2是%d\n", 12 >> 2);
	return 0;
}



