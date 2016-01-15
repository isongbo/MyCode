/*
   指针作业
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0, tmp = 0;
	int *p_num = &num, *p_num1 = &num1, *p_tmp = &tmp;
	printf("请输入两个数字：");
	scanf("%d%d", p_num, p_num1);
	*p_tmp = *p_num;
	*p_num = *p_num1;
	*p_num1 = *p_tmp;
	printf("num是%d,num1是%d\n", *p_num, *p_num1);
	return 0;
}



