/*
   二维数组演示
   */
#include <stdio.h>
int main() {
	int arr[2][3] = {1, 2, 3, 4, 5, 6};
	printf("arr是%p\n", arr);
	printf("&arr[0][0]是%p\n", &arr[0][0]);
	//arr = 0;    错误
	printf("arr + 1是%p\n", arr + 1);
	printf("&arr[1][0]是%p\n", &arr[1][0]);
	printf("sizeof(arr)是%d\n", sizeof(arr));
	return 0;
}



