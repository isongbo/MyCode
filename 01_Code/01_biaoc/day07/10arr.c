/*
   数组练习
   */
#include <stdio.h>
int main() {
	int arr[15];
	int num = 0, pos = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	//拆分所有数位并从后向前记录在
	//数组中
	for (pos = 14;pos >= 0;pos--) {
		arr[pos] = num % 10;
		num /= 10;
		if (!num) {
			break;
		}
	}
	//从前向后把所有拆分出来的数位数字
	//打印在屏幕上
	for (;pos <= 14;pos++) {
		printf("%d ", arr[pos]);
	}
	printf("\n");
	return 0;
}



