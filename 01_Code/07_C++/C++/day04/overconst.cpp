#include <iostream>
using namespace std;
class A {
public:
	/*
	void foo (void) {
		cout << "A::foo(void)" << endl;
	}
	// void foo (A* this) { ... }
	*/
	void foo (void) const {
		cout << "A::foo(void)const" << endl;
	}
	// void foo (A const* this) { ... }
};
int main (void) {
	A a;
	a.foo (); // foo (&a);
	A const& r = a;
	r.foo (); // foo (&r);
	A const* p = &a;
	p->foo (); // foo (p);
	return 0;
}
