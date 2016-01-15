/*
   字符串标准函数演示
   */
#include <stdio.h>
#include <string.h>
int main() {
	char str[20] = "abc";
    printf("有效字符个数是%d\n", strlen("abc"));
	printf("合并结果是%s\n", strcat(str, "xyz"));
	printf("合并结果是%s\n", str);
	printf("比较结果是%d\n", strcmp("abc", "abd"));
	printf("复制结果是%s\n", strcpy(str, "qewdt"));
	printf("复制结果是%s\n", str);
	return 0;
}



