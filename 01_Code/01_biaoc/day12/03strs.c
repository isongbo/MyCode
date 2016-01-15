/*
   多个字符串记录演示
   */
#include <stdio.h>
int main() {
	//char strs[][10] = {"China", "Russia", 
	char *strs[] = {"China", "Russia",
		"America", "England", "France"};
	int num = 0;
	printf("sizeof(strs)是%d\n", sizeof(strs));
	for (num = 0;num <= 4;num++) {
		printf("%s\n", strs[num]);
	}
	return 0;
}
