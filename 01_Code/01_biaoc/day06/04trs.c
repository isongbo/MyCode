/*
   类型转换演示
   */
#include <stdio.h>
int main() {
	char ch = 0;
	int num = 0;
	printf("sizeof(1 ? 1 : 0.9)是%d\n", sizeof(1 ? 1 : 0.9));
	printf("-7 + 3 > 0是%d\n", -7 + 3 > 0);
	printf("-7 + 3u > 0是%d\n", -7 + 3u > 0);
    num = (char)300;
	printf("num是%d\n", num);
	return 0;
}




