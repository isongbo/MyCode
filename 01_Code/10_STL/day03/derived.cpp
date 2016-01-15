#include <iostream>
using namespace std;
template<typename T>
class X : public T {
public:
	void bar (void) const {
		T::foo ();
		cout << "X::bar" << endl;
	}
};
class A {
public:
	void foo (void) const {
		cout << "A::foo" << endl;
	}
};
class B {
public:
	void foo (void) const {
		cout << "B::foo" << endl;
	}
};
/*
class X : public A {
public:
	void bar (void) const {
		foo ();
	}
};
*/
int main (void) {
	X<A> xa;
	xa.bar ();
	X<B> xb;
	xb.bar ();
	return 0;
}
