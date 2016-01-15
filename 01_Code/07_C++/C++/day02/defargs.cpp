#include <iostream>
using namespace std;
void foo (void) {}
void foo (
	char        a = 'C',
	int         b = 8888,
	double      c = 3.14159, 
	char const* d = "缺省字符串");
/*
int mul (int x, int y = x) {
	return x * y;
}*/
void bar (int) {
	// ...
}
void hum (int x, int y) {
	cout << "hum(int,int)" << endl;
}
void hum (int x, int y, int) {
	cout << "hum(int,int,int)" << endl;
}
// ++ -> operator++
int main (void) {
	foo ('A', 1234, 1.23, "Hello, World !");
	foo ('A', 1234, 1.23);
	foo ('A', 1234);
	foo ('A');
//	foo (); // 重载歧义
//	foo (,1234,,);
//	cout << mul (12, 4) << endl;
//	cout << mul (12) << endl;
	return 0;
}
void foo (
	char        a /* = 'C' */,
	int         b /* = 8888 */,
	double      c /* = 3.14159 */, 
	char const* d /* = "缺省字符串" */) {
	cout << a << ' ' << b << ' ' << c << ' '
		<< d << endl;
	bar (100);
	hum (1, 2);
	hum (1, 2, 3);
}
