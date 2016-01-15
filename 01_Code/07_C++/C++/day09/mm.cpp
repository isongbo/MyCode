#include <iostream>
using namespace std;
typedef void (*PFUN) (void*);
typedef PFUN* VPTR;
class A {
public:
	virtual void foo (void) {
		cout << "A::foo(void)" << endl;
	}
};
class B {
public:
	virtual void bar (void) {
		cout << "B::bar(void)" << endl;
	}
};
class C : public A, public B {
public:
	void foo (void) {
		cout << "C::foo(void)" << endl;
	}
	void bar (void) {
		cout << "C::bar(void)" << endl;
	}
};
int main (void) {
	C c;
	A* p = &c;
	p->foo ();
//	p->bar ();
	B& r = c;
//	r.foo ();
	r.bar ();
	cout << "----------------" << endl;
	VPTR vptra = *(VPTR*)&c;
	vptra[0] ();
	VPTR vptrb = vptra + 1;
	vptrb[0] ();
	return 0;
}
