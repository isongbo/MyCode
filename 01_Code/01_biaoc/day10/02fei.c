/*
   费氏数列作业
   */
#include <stdio.h>
int fei(int num) {
	if (num <= 2) {
		return 1;
	}
	return fei(num - 2) + fei(num - 1);
}
int main() {
    int num = 0;
	printf("请输入编号：");
	scanf("%d", &num);
	num = fei(num);
	printf("结果是%d\n", num);
	return 0;
}





