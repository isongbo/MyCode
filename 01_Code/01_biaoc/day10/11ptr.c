/*
   指针练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0, num2 = 0;
	int *p_max = &num, *p_mid = &num1, *p_min = *num2, *p_tmp = NULL;
	if (*p_max < *p_mid) {
		p_tmp = p_max;
		p_max = p_mid;
		p_mid = p_tmp;
	}
	if (*p_max < *p_min) {
		p_tmp = p_max;
		p_max = p_min;
		p_min = p_tmp;
	}
	if (*p_min > *p_mid) {
		p_tmp = p_mid;
		p_mid = p_min;
		p_min = p_tmp;
	}
	printf("%d %d %d\n", *p_max, *p_mid, *p_min);
	return 0;
}
