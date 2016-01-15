/*
   指针演示
   */
#include <stdio.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int *p_num = NULL;
	for (p_num = arr;p_num <= arr + 4;p_num++) {
		printf("%d ", *p_num);
	}
	printf("\n");
	return 0;
}
