#include <cstdlib>
#include <iostream>
using namespace std;
template<typename T>
class A {
public:
	class X {};
	void foo (void) {}
	int m_data;
	void exit (int status) {
		cout << "再见！" << endl;
	}
};
template<typename T>
class B : public A<T> {
public:
	void bar (void) {
		typename A<T>::X x;
//		A<T>::foo ();
//		A<T>::m_data++;
		this->foo ();
		this->m_data++;
		this->exit (0);
	}
};
int main (void) {
	B<int> b;
	b.bar ();
	return 0;
}
