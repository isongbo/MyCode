#include <iostream>
using namespace std;
class A {
public:
	int m_pub;
protected:
	int m_pro;
private:
	int m_pri;
};
//class B : public A {
//class B : protected A {
class B : private A {
public:
	void foo (void) {
		m_pub = 10;
		m_pro = 20;
//		m_pri = 30;
	}
};
class C : public B {
public:
	void bar (void) {
//		m_pub = 10;
//		m_pro = 20;
//		m_pri = 30;
	}
};
int main (void) {
	B b;
	b.foo ();
//	b.m_pub = 10;
//	b.m_pro = 10;
//	b.m_pri = 10;
	return 0;
}
