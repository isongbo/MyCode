/*
   fread演示
   */
#include <stdio.h>
int main() {
	int arr[10] = {}, size = 0, num = 0;
	FILE *p_file = fopen("a.bin", "rb");
	if (p_file) {
		size = fread(arr, sizeof(int), 10, p_file);
		printf("一共读出%d个整数类型存储区\n", size);
		for (num = 0;num <= size - 1;num++) {
			printf("%d ", arr[num]);
		}
		printf("\n");
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
