/*
   费氏数列作业
   */
#include <stdio.h>
int arr[50];
int fei(int num) {
	if (num <= 2) {
		return 1;
	}
	if (!arr[num - 2]) {
		arr[num - 2] = fei(num - 2);
	}
	if (!arr[num - 1]) {
		arr[num - 1] = fei(num - 1);
	}
	return arr[num - 2] + arr[num - 1];
}
int main() {
    int num = 0;
	printf("请输入编号：");
	scanf("%d", &num);
	num = fei(num);
	printf("结果是%d\n", num);
	return 0;
}





