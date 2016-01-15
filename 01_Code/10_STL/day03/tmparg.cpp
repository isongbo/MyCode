#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
class X {
public:
	T m_x;
};
template<typename T>
class Y {
public:
	T m_y;
};
template<typename T,
	template<typename> class Z>
class A {
public:
	Z<T> m_a;
};
template<typename T,
	template<typename> class Z>
void foo (void) {
	Z<T> zt;
	cout << typeid (zt).name () << endl;
}
int main (void) {
	A<int, X> a;
	cout << typeid (a.m_a.m_x).name() << endl;
	A<double, Y> b;
	cout << typeid (b.m_a.m_y).name() << endl;
	foo<int, X> ();
	foo<double, Y> ();
	return 0;
}
