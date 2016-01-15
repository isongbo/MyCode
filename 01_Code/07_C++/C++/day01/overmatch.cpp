#include <iostream>
using namespace std;
void foo (char* p, int n) {
	cout << "foo(char*,int)" << endl;
}
void foo (const char* p, char c) {
	cout << "foo(const char*,char)" << endl;
}
void bar (char c) {
	cout << "bar(char)" << endl;
}
void bar (int n) {
	cout << "bar(int)" << endl;
}
void bar (long long l) {
	cout << "bar(long long)" << endl;
}
void hum (double f, ...) {
	cout << "hum(double,...)" << endl;
}
void hum (int n, void* p) {
	cout << "hum(int,void*)" << endl;
}
int main (void) {
	char* p;
	char c;
	foo (p, c); // 常量转换>升级转换
	short s;
	bar (s); // 升级转换>标准转换
	double f;
	void* q;
	hum (f, q); // 标准转换>省略号匹配
	return 0;
}
