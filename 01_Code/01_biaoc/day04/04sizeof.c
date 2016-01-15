/*
   sizeof演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	short snum = 0;
	printf("sizeof(num)是%d,sizeof(snum)是%d\n", sizeof(num), sizeof(snum));
	printf("sizeof(int)是%d,sizeof(short)是%d\n", sizeof(int), sizeof(snum));
	printf("sizeof(2 + 3)是%d\n", sizeof(2 + 3));
	sizeof(num = 10);
	printf("num是%d\n", num);
	return 0;
}



