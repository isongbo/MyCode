#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
class X {
public:
	T m_x;
};
template<typename T>
class A {
public:
	X<T> m_a;
};
int main (void) {
	A<int> a;
	cout << typeid (a.m_a.m_x).name() << endl;
	return 0;
}
