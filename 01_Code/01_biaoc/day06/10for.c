/*
   for循环练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0, res = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
    for (num1 = 2;num1 <= num - 1;num1++) {
		if (!(num % num1)) {
			res = 1;
			break;
		}
	}
	if (num1 <= num - 1) {
		printf("数字%d不是素数\n", num);
	}
	else {
		printf("数字%d是素数\n", num);
	}
	return 0;
}




