/*
   彩票练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create(int arr[], int size) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		arr[num] = rand() % 36 + 1;
	}
}
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



