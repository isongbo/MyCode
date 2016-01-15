/*
   文件操作演示
   */
#include <stdio.h>
int main() {
	FILE *p_file = fopen("a.txt", "w");
	/*if (p_file) {
		//
		fclose(p_file);
		p_file = NULL;
	}*/
	if (!p_file) {
		return 0;
	}
	//
	fclose(p_file);
	p_file = NULL;
	return 0;
}


