/*
   无类型指针作为函数形式参数演示
   */
#include <stdio.h>
void print(const void *p_v, int type) {
	if (type == 1) {
		printf("%c\n", *(char *)p_v);
	}
	else if (type == 2) {
		printf("%d\n", *(int *)p_v);
	}
	else {
		printf("%g\n", *(float *)p_v);
	}
}
int main() {
	int num = 4;
	float fnum = 5.23f;
	char ch = 't';
	print(&ch, 1);
	print(&num, 2);
	print(&fnum, 3);
	return 0;
}
