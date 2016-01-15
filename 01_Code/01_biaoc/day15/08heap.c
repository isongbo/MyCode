/*
   动态分配内存演示
   */
#include <stdio.h>
#include <stdlib.h>
int main() {
	int num = 0;
    int *p_num = (int *)malloc(5 * sizeof(int));
	if (p_num) {
		//
		for (num = 0;num <= 4;num++) {
			*(p_num + num) = num + 1;
			//p_num[num] = num + 1;
		}
		for (num = 4;num >= 0;num--) {
			printf("%d ", *(p_num + num));
		}
		printf("\n");
		free(p_num);
		p_num = NULL;
	}
	return 0;
}




