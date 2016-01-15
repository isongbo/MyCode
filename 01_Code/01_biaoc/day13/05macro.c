/*
   宏演示
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[SIZE] = {}, num = 0;
	srand(time(0));
	for (num = 0;num <= SIZE - 1;num++) {
		arr[num] = rand() % MAX + 1;
	}
	for (num = 0;num <= SIZE - 1;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}




