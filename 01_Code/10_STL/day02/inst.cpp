#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
class A {
public:
	T m_t;
};
template<typename T>
class B {
public:
	T m_t;
};
int main (void) {
	A<int> a;
	cout << typeid (a.m_t).name () << endl;
	B<A<int> > b;
	cout << typeid (b.m_t).name () << endl;
	// 递归实例化
	A<A<int> > c;
	cout << typeid (c.m_t).name () << endl;
	return 0;
}
