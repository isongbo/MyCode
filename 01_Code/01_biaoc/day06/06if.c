/*
   if分支练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0, num2 = 0;
	printf("请输入三个数字：");
	scanf("%d%d%d", &num, &num1, &num2);
	/*if (num > num1 && num > num2) {
		printf("最大数字是%d\n", num);
	}
	else if (num1 > num && num1 > num2) {
		printf("最大数字是%d\n", num1);
	}
	else {
		printf("最大数字是%d\n", num2);
	}*/
	if (num > num1) {
		if (num > num2) {
			printf("最大数字是%d\n", num);
		}
		else {
			printf("最大数字是%d\n", num2);
		}
	}
	else {
		if (num1 > num2) {
			printf("最大数字是%d\n", num1);
		}
		else {
			printf("最大数字是%d\n", num2);
		}
	}
	return 0;
}



