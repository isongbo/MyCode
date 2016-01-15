/*
   字符串演示
   */
#include <stdio.h>
#include <string.h>
int main() {
	char str[10] = {};
	printf("请输入一个字符串：");
	//scanf("%s", str);
	fgets(str, 10, stdin);
	if (strlen(str) == 9 && str[8] != '\n') {
		scanf("%*[^\n]");
		scanf("%*c");
	}
	printf("%s\n", str);
	return 0;
}
