/*
   递归演示
   */
#include <stdio.h>
void print(int num) {
	if (num == 1) {
		printf("1\n");
		return ;
	}
	printf("%d\n", num);
	print(num - 1);
}
int main() {
    print(3);
	return 0;
}
