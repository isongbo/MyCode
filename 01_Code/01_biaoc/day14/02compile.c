/*
   条件编译演示
   */
#include <stdio.h>
int main() {
#if  defined(JINGPIN)
	printf("120%%\n");
#elif   !defined(JINGPIN) && !defined(GONGCHANG)
	printf("100%%\n");
#else
	printf("80%%\n");
#endif
	return 0;
}
