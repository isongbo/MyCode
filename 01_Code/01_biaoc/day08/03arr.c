/*
   数组名称用法演示
   */
#include <stdio.h>
int main() {
	int arr[5] = {};
	printf("arr是%p\n", arr);
	printf("&arr[0]是%p\n", &arr[0]);
	//arr = 0;    错误
	printf("arr + 2是%p\n", arr + 2);
	printf("&arr[2]是%p\n", &arr[2]);
	printf("sizeof(arr)是%d\n", sizeof(arr));
	return 0;
}



