/*
   数据对齐和补齐演示
   */
#include <stdio.h>
typedef struct {
	char ch;
	int num;
} stru1;
typedef struct {
	char ch;
	int num;
	char ch1;
} stru2;
int main() {
	printf("sizeof(stru1)是%d\n", sizeof(stru1));
	printf("sizeof(stru2)是%d\n", sizeof(stru2));
	return 0;
}



