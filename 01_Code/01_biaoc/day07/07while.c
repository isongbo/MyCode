/*
   while练习
   */
#include <stdio.h>
int main() {
	int num = 0, cnt = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	/*while (num) {
		num /= 10;
		cnt++;
	}*/
    do {
		num /= 10;
		cnt++;
	} while (num);
	printf("数位个数是%d\n", cnt);
	return 0;
}



