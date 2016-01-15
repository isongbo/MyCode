/*
   字符串演示
   */
#include <stdio.h>
int main() {
	char str[] = "xyz";
	//char str[3] = "xyz";   错误
	printf("%p\n", "abc");
	printf("%p\n", "abc");
	printf("%p\n", "abc");
	printf("%p\n", "ab""c");
	printf("%c\n", *"abc");
	printf("%hhd\n", *("abc" + 3));
	printf("sizeof(str)是%d\n", sizeof(str));
	return 0;
}




