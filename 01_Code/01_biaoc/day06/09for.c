/*
   for循环练习
   */
#include <stdio.h>
int main() {
	int num = 0;
	for (num = 54321;num >= 5;num /= 10) {
		printf("%d\n", num);
	}
	return 0;
}
