/*
   宏操作符演示
   */
#include <stdio.h>
#define   STR(n)        #n
#define   LOCAL(n)      l_##n
int main() {
	int num = 0;
	int LOCAL(num) = 0;
    STR(2 + 3);
	return 0;
}
