/*
   无类型指针演示
   */
#include <stdio.h>
int main() {
	int num = 10;
	char ch = 100;
	void *p_v = &num;
	*(int *)p_v = 50;
	p_v = &ch;
	*(char *)p_v = 5;
	return 0;
}
