/*
   重名变量演示
   */
#include <stdio.h>
int num;
int main() {
	printf("num是%d\n", num);
	int num = 1;
	printf("num是%d\n", num);
	{
	    printf("num是%d\n", num);
		int num = 2;
	    printf("num是%d\n", num);
	}
	printf("num是%d\n", num);
	return 0;
}
