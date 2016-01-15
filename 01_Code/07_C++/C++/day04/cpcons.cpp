#include <iostream>
using namespace std;
class B {
public:
	B (void) {
	}
	B (B const& b) {
		cout << "B拷贝构造" << endl;
		m_data = b.m_data;
	}
	int m_data;
};
class A {
public:
	A (void) {}
	A (A const& a) : m_b (a.m_b) {
		cout << "A拷贝构造" << endl;
	}
	B m_b;
};
A foo (A a) {
	return a;
}
int main (void) {
	A a1;
	a1.m_b.m_data = 1234;
	A a2 = a1;
	cout << a2.m_b.m_data << endl;
	A a3 = foo (a2);
	return 0;
}
