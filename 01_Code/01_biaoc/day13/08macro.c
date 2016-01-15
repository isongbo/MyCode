/*
   宏练习
   */
#include <stdio.h>
#define   SUB(x, y)        ((x) - (y))
#define   SQUARE(n)        ((n) * (n))
int main() {
	int num = 6;
	printf("SUB(10, 6)是%d\n", SUB(10, 6));
	printf("20 - SUB(10, 4)是%d\n", 20 - SUB(10, 4));
    printf("SUB(20, 10 - 4)是%d\n", SUB(20, 10 - 4));
	printf("SQUARE(++num)是%d\n", SQUARE(++num));
	return 0;
}
