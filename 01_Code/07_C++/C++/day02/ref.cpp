#include <iostream>
using namespace std;
int calc (int x, int y, int* z) {
	*z = x - y;
	return x + y;
}
int calc (int x, int y, int& z) {
	z = x - y;
	return x + y;
}
void swap1 (int x, int y) {
	int z = x;
	x = y;
	y = z;
}
void swap2 (int* x, int* y) {
	int z = *x;
	*x = *y;
	*y = z;
}
void swap3 (int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}
void swap4 (char const* x, char const* y) {
	char const* z = x;
	x = y;
	y = z;
}
void swap5 (char const** x, char const** y) {
	char const* z = *x;
	*x = *y;
	*y = z;
}
void swap6 (char const*& x, char const*& y) {
	char const* z = x;
	x = y;
	y = z;
}
int main (void) {
	int a = 10;
	int& b = a;
	int& c = b;
	cout << &a << ' ' << &b << ' ' << &c
		<< endl;
	b = 20;
	++c;
	a -= 5;
	cout << b << endl; // 16
//	int& d;
	int& d = a;
	int e = 100;
	d = e;
	cout << a << endl;
	int sum, sub;
//	sum = calc (456, 123, &sub);
	sum = calc (456, 123, sub);
	cout << sum << ' ' << sub << endl;
	int x = 100, y = 200;
//	swap1 (x, y);
//	swap2 (&x, &y);
	swap3 (x, y);
	cout << x << ' ' << y << endl;
	char const* p = "hello";
	char const* q = "world";
//	swap4 (p, q);
//	swap5 (&p, &q);
	swap6 (p, q);
	cout << p << ' ' << q << endl;
	return 0;
}
