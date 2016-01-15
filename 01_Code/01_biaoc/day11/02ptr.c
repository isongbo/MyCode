/*
   指针作业
   */
#include <stdio.h>
int main() {
	float fnum = 1.0f;
	printf("转换结果是0x%x\n", *(int *)&fnum);
	return 0;
}
