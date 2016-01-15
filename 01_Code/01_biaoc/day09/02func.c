/*
   返回值练习
   */
#include <stdio.h>
int read(void) {
	int num = 0;
	printf("请输入数字：");
	scanf("%d", &num);
	return num;
}
int main() {
    int num = read();
	printf("num是%d\n", num);
	return 0;
}



