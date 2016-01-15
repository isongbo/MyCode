#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
void foo (T const& x, T const& y) {
	cout << typeid (x).name () << ' '
		<< typeid (y).name () << endl;
}
template<typename T>
void bar (T x, T y) {
	cout << typeid (x).name () << ' '
		<< typeid (y).name () << endl;
}
void hum (int const& x, int const& y) {
	cout << x << ' ' << y << endl;
}
template<typename T, typename U>
T fun (U x) {
	T t;
	return t;
}
int main (void) {
	int a, b;
	foo (a, b);
	double c, d;
	foo (c, d);
	char e[256], f[256];
	foo (e, f);
	bar (e, f);
	// e[2] <=> *(e+2)
	// sizeof(e) -> 256
	// &e
	// cout << (void*)&e << ' ' << (void*)e
	//     << endl;
//	foo ("hello", "tarena");
	bar ("hello", "tarena");
	string g = "hello", h = "tarena";
	foo (g, h);
	hum (a, c);
//	foo (a, c);
	foo (a, (int)c);
	foo ((double)a, c);
	foo<int> (a, c);
	foo<double> (a, c);
	string s = fun<string> (10);
	return 0;
}
