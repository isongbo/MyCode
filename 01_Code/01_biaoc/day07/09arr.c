/*
   数组演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	int arr[5];    //数组声明
	arr[3] = 10;
	for (num = 0;num <= 4;num++) {
		arr[num] = num + 1;
	}
	for (num = 4;num >= 0;num--) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}



