#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
T foo (T x, T y) {
	cout << typeid (T).name () << endl;
}
template<typename T>
T const& bar (T const& x, T const& y) {
	cout << typeid (T).name () << endl;
}
void foo (int x[5], int y[5], int z[5]) {
	for (int i = 0; i < 5; ++i)
		z[i] = x[i] + y[i];
}
struct Z {
	int z[5];
};
Z hum (int x[5], int y[5]) {
	Z zz;
	for (int i = 0; i < 5; ++i)
		zz.z[i] = x[i] + y[i];
	return zz;
}
int main (void) {
	int a[5];
	foo (a, a);
	bar (a, a);
	int x[5] = {1, 2, 3, 4, 5};
	int y[5] = {10, 20, 30, 40, 50};
	int z[5];
	foo (x, y, z);
	for (int i = 0; i < 5; ++i)
		cout << z[i] << ' ';
	cout << endl;
	Z zz = hum (x, y);
	for (int i = 0; i < 5; ++i)
		cout << zz.z[i] << ' ';
	cout << endl;
	return 0;
}
