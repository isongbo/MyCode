/*
   二级指针形式参数演示
   */
#include <stdio.h>
#include <stdlib.h>
void read(int **pp_num) {
    *pp_num = (int *)malloc(sizeof(int));
	if (*pp_num) {
		printf("请输入一个数字：");
		scanf("%d", *pp_num);
	}
}
int main() {
	int *p_num = NULL;
	read(&p_num);
	if (p_num) {
		printf("%d\n", *p_num);
		free(p_num);
		p_num = NULL;
	}
	return 0;
}
