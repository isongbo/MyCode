/*
   数组形式参数演示
   */
#include <stdio.h>
void neg(int arr[], int size) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		arr[num] = 0 - arr[num];
	}
}
void func(int arr[], int size) {
	printf("sizeof(arr)是%d\n", sizeof(arr));
}
int main() {
	int arr[5] = {1, 2, 3, 4, 5}, num = 0;
	func(arr, 5);
	neg(arr, 5);
	for (num = 0;num <= 4;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}
