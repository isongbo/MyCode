#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
};
class B {
public:
	B (void) {
		cout << "B构造" << endl;
	}
private:
	A m_a;
};
class C {
public:
	C (void) {
		cout << "C构造" << endl;
	}
private:
	A m_a;
	B m_b;
//	A m_a;
};
int main (void) {
	C c;
	return 0;
}
