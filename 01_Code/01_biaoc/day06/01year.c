/*
   闰年作业
   */
#include <stdio.h>
int main() {
	int year = 0, res = 0;
	printf("请输入一个年份数字：");
	scanf("%d", &year);
	res = (!(year % 4) && (year % 100)) || !(year % 400);
	printf("判断结果是%d\n", res);
	return 0;
}
