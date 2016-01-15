/*
   指针形式参数演示
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *create(int *p_num, int size) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		*(p_num + num) = rand() % 36 + 1;
	}
	return p_num;
}
//以下函数错误
int *create1(void) {
	int arr[7] = {};
	int num = 0;
	for (num = 0;num <= 6;num++) {
		arr[num] = rand() % 36 + 1;
	}
	return arr;
}
int main() {
	int arr[7] = {}, num = 0;
	int *p_num = NULL;
	srand(time(0));
	p_num = create(arr, 7);
	for (num = 0;num <= 6;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	for (num = 0;num <= 6;num++) {
		printf("%d ", *(p_num + num));
	}
	printf("\n");
	return 0;
}



