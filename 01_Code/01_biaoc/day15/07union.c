/*
   联合演示
   */
#include <stdio.h>
union un {
	char ch;
	int num;
};
int main() {
    printf("sizeof(union un)是%d\n", sizeof(union un));
	return 0;
}
