#include <iostream>
using namespace std;
class A {
public:
	A (int data) : m_data (data) {}
	int m_data;
};
class X {
public:
	virtual A foo (void) {
		return A (100);
	}
};
class Y : public X {
public:
	A foo (void) {
		return A (200);
	}
};
int main (void) {
	Y y;
	X& x = y;
	cout << x.foo ().m_data << endl;
	X z = y;
	cout << z.foo ().m_data << endl;
	return 0;
}
