/*
   指针和数组演示
   */
#include <stdio.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int num = 0;
	int *p_num = arr, *p_num1 = arr + 3;
	for (num = 0;num <= 4;num++) {
		printf("%d ", arr[num]);
		printf("%d ", p_num[num]);
		printf("%d ", *(p_num + num));
	}
	printf("\n");
	printf("p_num是%p,p_num - 3是%p\n", p_num, p_num - 3);
	printf("结果是%d\n", p_num1 - p_num);
	return 0;
}



