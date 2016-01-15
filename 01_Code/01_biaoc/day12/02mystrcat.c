/*
   mystrcat作业
   */
#include <stdio.h>
char *mystrcat(char *p_dest, const char *p_src) {
	char *p_dest1 = p_dest;
	const char *p_src1 = p_src;
	//查找'\0'字符所在位置
	while (*p_dest1) {
		p_dest1++;
	}
    //拷贝所有字符
	while (*p_src1) {
        *p_dest1 = *p_src1;
		p_src1++;
		p_dest1++;
	}
	*p_dest1 = 0;
	return p_dest;
}
int main() {
	char str[10] = "abc";
	printf("%s\n", mystrcat(str, "xyz"));
	printf("%s\n", str);
	return 0;
}





