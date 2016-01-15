/*
   回调函数演示
   */
#include <stdio.h>
void neg(int *p_num, void *p_v) {
	*p_num = 0 - *p_num;
}
void print(int *p_num, void *p_v) {
	printf("%d ", *p_num);
}
void sum(int *p_num, void *p_v) {
    *(int *)p_v += *p_num;
}
void for_each(int *p_num, int size, void (*p_func)(int*, void*), void *p_v) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		p_func(p_num + num, p_v);
	}
}
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int res = 0;
	//print(arr, 5);
	for_each(arr, 5, print, NULL);
	printf("\n");
	for_each(arr, 5, neg, NULL);
	for_each(arr, 5, print, NULL);
	printf("\n");
	for_each(arr, 5, sum, &res);
	printf("求和结果是%d\n", res);
	return 0;
}



