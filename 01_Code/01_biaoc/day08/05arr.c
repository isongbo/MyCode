/*
   二维数组演示
   */
#include <stdio.h>
int main() {
	//int arr[2][3];   //二维数组声明
	//int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
	//int arr[2][3] = {1, 2, 3, 4, 5, 6};
	//int arr[2][3] = {1, 2, 3};
	//int arr[2][3] = {{1, 2}, {4, 5}};
	//int arr[][3] = {1, 2, 3, 4};
	int arr[][3] = {{1, 2}, {3}};
	int row = 0, col = 0, num = 1;
	//arr[1][2] = 10;
	/*for (row = 0;row <= 1;row++) {
		for (col = 0;col <= 2;col++) {
			arr[row][col] = num;
			num++;
		}
	}*/
	for (row = 0;row <= 1;row++) {
		for (col = 0;col <= 2;col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}


