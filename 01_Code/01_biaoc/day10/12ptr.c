/*
   指针演示
   */
#include <stdio.h>
int main() {
	int num = 300;
	int *p_num = &num;
	char *p_ch = p_num;
	printf("sizeof(p_num)是%d,sizeof(p_ch)是%d\n", sizeof(p_num), sizeof(p_ch));
	printf("p_num是%p,p_ch是%p\n", p_num, p_ch);
	printf("*p_num是%d,*p_ch是%d\n", *p_num, *p_ch);
	printf("*(char *)p_num是%d\n", *(char *)p_num);
	return 0;
}


