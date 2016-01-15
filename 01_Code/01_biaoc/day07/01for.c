/*
   循环作业
   */
#include <stdio.h>
int main() {
	int num = 0;
	for (num = 1;num <= 5;num++) {
		printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
	}
	return 0;
}
