#include <iostream>
#include <cstring>
using namespace std;
class A {
public:
	virtual void foo (void) {
		cout << "A::foo(void)" << endl;
	}
};
class B : public A {
public:
	void foo (void) {
		cout << "B::foo(void)" << endl;
	}
};
int main (void) {
	A a;
	a.foo ();
	B b;
	b.foo ();
//	a = b;
	memcpy (&a, &b, sizeof (a));
	a.foo ();
	A* p = &a;
	p->foo ();
	return 0;
}
