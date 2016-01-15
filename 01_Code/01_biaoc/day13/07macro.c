/*
   宏演示
   */
#include <stdio.h>
#define    ABS(n)    n >= 0 ? n : 0 - n
int abs(int num) {
	if (num >= 0) {
		return num;
	}
	else {
		return 0 - num;
	}
}
#define    NEG(n)         n = 0 - n
void neg(int num) {
	num = 0 - num;
}
int main() {
	int num = 10;
    printf("abs(-6)是%d\n", abs(-6));
    printf("ABS(-6)是%d\n", ABS(-6));
	neg(num);
	printf("num是%d\n", num);
	NEG(num);
	printf("num是%d\n", num);
	return 0;
}




