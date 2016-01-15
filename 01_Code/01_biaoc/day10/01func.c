/*
   函数作业
   */
#include <stdio.h>
void print(int num, int num1) {
	printf("%d X %d = %d\n", num, num1, num * num1);
}
int main() {
	int num = 0;
	for (num = 1;num <= 5;num++) {
        print(num, 10 - num);
	}
	return 0;
}



