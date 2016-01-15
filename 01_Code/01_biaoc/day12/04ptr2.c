/*
   二级指针演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	int *p_num = &num;
	int **pp_num = &p_num;
	printf("pp_num是%p\n", pp_num);
	printf("*pp_num是%p\n", *pp_num);
	printf("**pp_num是%d\n", **pp_num);
	return 0;
}





