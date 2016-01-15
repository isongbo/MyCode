/*
   动态分配内存演示
   */
#include <stdio.h>
#include <stdlib.h>
int *read(void) {
	int *p_num = (int *)malloc(sizeof(int));
	if (p_num) {
		printf("请输入一个数字：");
		scanf("%d", p_num);
	}
	return p_num;
}
int main() {
    int *p_num = read();
	if (p_num) {
		printf("%d\n", *p_num);
		free(p_num);
		p_num = NULL;
	}
	return 0;
}
