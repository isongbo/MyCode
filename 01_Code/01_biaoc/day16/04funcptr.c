/*
   函数指针演示
   */
#include <stdio.h>
int add(int num, int num1) {
	return num + num1;
}
int sub(int num, int num1) {
	return num - num1;
}
int mul(int num, int num1) {
	return num * num1;
}
int div(int num, int num1) {
	return num / num1;
}
int main() {
	char opr = 0;
	int num = 0, num1 = 0, res = 0;
	int (*p_func)(int, int) = NULL;
	printf("请输入表达式：");
	scanf("%d%c%d", &num, &opr, &num1);
	if (opr == '+') {
		p_func = add;
	}
	else if (opr == '-') {
		p_func = sub;
	}
	else if (opr == '*') {
		p_func = mul;
	}
	else {
		p_func = div;
	}
	res = p_func(num, num1);
	printf("计算结果是%d\n", res);
	return 0;
}




