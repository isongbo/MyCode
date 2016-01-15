/*
   递归函数演示
   */
#include <stdio.h>
void print(void) {
	printf("1\n");
	print();
}
int main() {
    print();
	return 0;
}
