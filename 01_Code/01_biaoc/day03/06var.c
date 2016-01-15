/*
   变量练习
   */
#include <stdio.h>
int main() {
	int num = 1, ten = 10;
	printf("%d X %d = %d\n", num, ten - num, num * (ten - num));
	num++;
	printf("%d X %d = %d\n", num, ten - num, num * (ten - num));
	num++;
	printf("%d X %d = %d\n", num, ten - num, num * (ten - num));
	num++;
	printf("%d X %d = %d\n", num, ten - num, num * (ten - num));
	num++;
	printf("%d X %d = %d\n", num, ten - num, num * (ten - num));
	return 0;
}
