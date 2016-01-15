#include <iostream>
#include <typeinfo>
using namespace std;
template<typename X>
class A {
public:
	X m_x;
	/*
	template<typename Y>
	class B {
	public:
		Y m_y;
	};
	*/
	template<typename Y>
	class B;
};
template<typename X>
	template<typename Y>
class A<X>::B {
public:
	Y m_y;
};
int main (void) {
	A<int>::B<double> b;
	cout << typeid (b.m_y).name () << endl;
	return 0;
}
