extern "C" { // 花括号之内的函数按照C的方式
             // 生成其接口规格，即不换名
int add (int x, int y) {
	return x + y;
}
int sub (int x, int y) {
	return x - y;
}
}
/*extern "C" */double add (double x,
	double y) {
	return x + y;
}
