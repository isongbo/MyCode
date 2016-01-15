/*
   条件编译演示
   */
#include <stdio.h>
int main() {
#ifndef    ER
	printf("1\n");
#else
	printf("2\n");
#endif
	return 0;
}
