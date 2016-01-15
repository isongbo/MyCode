#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		foo (); // this->foo ();
	}
	~A (void) {
		foo (); // this->foo ();
	}
	virtual void foo (void) {
		cout << "A::foo(void)" << endl;
	}
	void bar (void) {
		foo (); // this->foo ();
	}
};
class B : public A {
public:
	void foo (void) {
		cout << "B::foo(void)" << endl;
	}
};
int main (void) {
	B b;
	/*
	A a = b;
	a.foo ();
	A& r = b;
	r.foo ();
	b.bar ();
	*/
	return 0;
}
