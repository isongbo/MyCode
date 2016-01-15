/*
   循环嵌套练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	for (num = 1;num <= 9;num++) {
		for (num1 = 1;num1 <= num;num1++) {
			printf("%dX%d=%2d ", num, num1, num * num1);
		}
		printf("\n");
	}
	return 0;
}
