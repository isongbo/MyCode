/*
   数组初始化演示
   */
#include <stdio.h>
int main() {
	//int arr[5] = {1, 2, 3, 4, 5};
	//int arr[5] = {1, 2, 3, 4, 5, 6, 7};
	//int arr[5] = {1, 2, 3};
	int arr[] = {1, 2, 3, 4, 5};
	int num = 0;
	for (num = 0;num <= 4;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}
