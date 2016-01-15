/*
   if分支演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	/*if (num >= 0) {
	    printf("1\n");
	}
	else if (num < 0) {
		printf("2\n");
	}*/
    /*if (num > 0) {
		printf("正数\n");
	}
	else if (num < 0) {
		printf("负数\n");
	}
	else {
		printf("零\n");
	}*/
	if (num < 0) {
		printf("负数\n");
	}
	else if (num % 2) {
		printf("奇数\n");
	}
	else {
		printf("偶数\n");
	}
	return 0;
}








