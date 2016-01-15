/*
   循环嵌套演示
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	for (num = 1;num <= 5;num++) {
		for (num1 = 5;num1 >= num;num1--) {
			printf("%d", num1);
		}
		printf("\n");
	}
	return 0;
}
