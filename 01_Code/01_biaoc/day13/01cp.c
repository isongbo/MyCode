/*
   拷贝作业
   */
#include <stdio.h>
int main(int argc, char *argv[]) {
	char buf[100] = {};
	int size = 0;
	FILE *p_src = fopen(argv[1], "rb");
	FILE *p_dest = NULL;
	if (!p_src) {
		printf("原始文件打开失败\n");
		return 0;
	}
    p_dest = fopen(argv[2], "wb");
	if (!p_dest) {
		fclose(p_src);
		p_src = NULL;
		printf("新文件打开失败\n");
		return 0;
	}
	while (size = fread(buf, sizeof(char), 100, p_src)) {
		fwrite(buf, sizeof(char), size, p_dest);
	}
	fclose(p_dest);
	p_dest = NULL;
	fclose(p_src);
	p_src = NULL;
	return 0;
}
