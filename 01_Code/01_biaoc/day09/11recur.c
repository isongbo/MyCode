/*
   递归练习
   */
#include <stdio.h>
int sum(int num) {
	if (num == 1) {
		return 1;
	}
	return num + sum(num - 1);
}
int main() {
	printf("%d\n", sum(10));
	return 0;
}



