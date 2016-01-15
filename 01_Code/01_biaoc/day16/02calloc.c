/*
   calloc演示
   */
#include <stdio.h>
#include <stdlib.h>
int main() {
	int *p_num = (int *)calloc(5, sizeof(int));
	int num = 0;
	if (p_num) {
        for (num = 0;num <= 4;num++) {
			printf("%d ", *(p_num + num));
		}
		printf("\n");
		free(p_num);
		p_num = NULL;
	}
	return 0;
}
