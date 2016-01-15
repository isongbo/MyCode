/*
   循环嵌套练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	for (num = 0;num <= 2;num++) {
        for (num1 = 0;num1 <= (10 - 5 * num) / 2;num1++) {
			printf("5元钱有%d张，2元钱有%d张，1元钱有%d张\n", num, num1, 10 - 5 * num - 2 * num1);
		}
	}
	return 0;
}
