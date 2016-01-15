#include <iostream>
using namespace std;
//int x = 123;
int& foo (void) {
//	static int x = 123;
//	return x;
	return *new int (123);
}
int& bar (void) {
	int y = 456;
	return y;
}
struct Counter {
	int cn;
//	int& add (void) {
	int const& add (void) {
		return ++cn;
	}
};
int& hum (int& r) {
	return r;
}
int main (void) {
	int& r = foo ();
	bar ();
	cout << r << endl;
	delete &r;
	Counter c = {0};
//	++++c.add ();
	cout << c.cn << endl; // 3
	int x = 100;
	int& rx = hum (x);
	cout << &rx << ' ' << &x << endl;
	return 0;
}
