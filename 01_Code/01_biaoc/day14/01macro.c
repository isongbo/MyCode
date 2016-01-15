/*
   宏作业
   */
#include <stdio.h>
#define  HEX(n)    ((n) >= '0' && (n) <= '9' ? (n) - '0' : (n) >= 'a' && (n) <= 'f' ? (n) - 'a' + 10 : (n) - 'A' + 10)
int main() {
	char ch = 0;
	printf("请输入一个字符：");
	scanf("%c", &ch);
	printf("转换结果是%d\n", HEX(ch));
	return 0;
}



