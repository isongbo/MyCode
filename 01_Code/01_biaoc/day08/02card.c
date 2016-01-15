/*
   身份证作业
   */
#include <stdio.h>
int main() {
	int card[17] = {};
	int arr[] = {7, 9, 10, 5, 8, 4, 2, 1,
	6, 3, 7, 9, 10, 5, 8, 4, 2};
	int val[] = {1, 0, -1, 9, 8, 7, 6,
	           5, 4, 3, 2};
	int num = 0, sum = 0;
	//从键盘获得身份证中前17个数字
	for (num = 0;num <= 16;num++) {
		printf("请输入一个数字：");
		//scanf("%d", &card[num]);
		scanf("%d", card + num);
	}
	//把身份证中前17个数位和另外一组
	//数字相乘并把结果相加
	for (num = 0;num <= 16;num++) {
		sum += card[num] * arr[num];
	}
	//用求和结果除以11取余到一组数字
	//中查找最终结果
	if (val[sum % 11] == -1) {
		printf("最后一位应该是X\n");
	}
	else {
		printf("最后一位应该是%d\n", val[sum % 11]);
	}
	return 0;
}


