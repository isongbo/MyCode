/*
   彩票作业
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*int *create(int size) {
    int *p_num = (int *)malloc(size * sizeof(int));
	int num = 0;
	if (p_num) {
		for (num = 0;num <= size - 1;num++) {
			*(p_num + num) = rand() % 36 + 1;
		}
	}
	return p_num;
}*/
void create1(int size, int **pp_num) {
	int num = 0;
	*pp_num = (int*)malloc(size * sizeof(int));
	if (*pp_num) {
		for (num = 0;num <= size - 1;num++) {
			*(*pp_num + num) = rand() % 36 + 1;
		}
	}
}
int main() {
	srand(time(0));
	//int *p_num = create(7);
	int *p_num = NULL;
	create1(7, &p_num);
	int num = 0;
	if (p_num) {
		for (num = 0;num <= 6;num++) {
			printf("%d ", *(p_num + num));
		}
		printf("\n");
		free(p_num);
		p_num = NULL;
	}
	return 0;
}



