/*
   点菜练习
   */
#include <stdio.h>
int main() {
	int order = 0;
	printf("请点菜：");
	scanf("%d", &order);
#ifdef    ZHAOBENSHAN
	if (order == 1) {
		printf("没有\n");
	}
	else {
		printf("真没有\n");
	}
#else
	if (order == 1) {
		printf("有\n");
	}
	else {
		printf("没有\n");
	}
#endif
	return 0;
}



