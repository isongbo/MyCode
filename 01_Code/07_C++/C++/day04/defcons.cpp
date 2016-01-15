#include <iostream>
using namespace std;
class B {
public:
	B (void) {
		m_data = 1234;
	}
	int m_data;
};
class A {
public:
	int m_data;
	B m_b;
};
class C {
public:
	C (int data) { m_data = data; }
	int m_data;
};
class D {
public:
	D (void) : m_c (5678) {}
	C m_c;
};
int main (void) {
	A a;
	cout << a.m_data << endl;
	cout << a.m_b.m_data << endl;
	C c (0);
//	C* pc = new C[3];
	D d;
	cout << d.m_c.m_data << endl;
	return 0;
}
