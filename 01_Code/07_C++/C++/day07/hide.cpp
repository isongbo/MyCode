#include <iostream>
using namespace std;
class A {
public:
	void foo (void) {
		cout << "A::foo(void)" << endl;
	}
	void foo (int x) {
		cout << "A::foo(int)" << endl;
	}
};
class B : public A {
public:
	void foo (int x) {
		cout << "B::foo(int)" << endl;
	}
	void foo (int x, int y) {
		cout << "B::foo(int,int)" << endl;
	}
	void foo (int x, int y, int z) {
		cout << "B::foo(int,int,int)" << endl;
		foo (x);
	}
	using A::foo;
};
int main (void) {
	B b;
//	b.A::foo ();
	b.A::foo (1);
	b.foo ();
	b.foo (1);
	b.foo (1, 2);
	b.foo (1, 2, 3);
	return 0;
}
