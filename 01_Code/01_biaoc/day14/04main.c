/*
   多文件编程练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "04create.h"
int main() {
	int arr[7] = {}, num = 0;
	srand(time(0));
	create(arr, 7);
	for (num = 0;num <= 6;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}




