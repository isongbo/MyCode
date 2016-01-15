/*
   数组演示
   */
#include <stdio.h>
int main() {
	int arr[3] = {1, 2, 3};
	int arr1[2][3] = {1, 2, 3, 4, 5, 6};
	printf("arr是%p,&arr是%p\n", arr, &arr);
	printf("arr + 1是%p,&arr + 1是%p\n", arr + 1, &arr + 1);
	printf("arr1[1]是%p, &arr1[1][0]是%p\n", arr1[1], &arr1[1][0]);
	printf("sizeof(arr1[1])是%d\n", sizeof(arr1[1]));
	printf("sizeof(*(arr1 + 1))是%d\n", sizeof(*(arr1 + 1)));
	printf("arr1[1] + 1是%p\n", arr1[1] + 1);
	return 0;
}
