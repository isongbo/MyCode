#include <iostream>
using namespace std;
class A {
public:
	virtual void foo (int x = 100) {
		cout << "A::foo()：" << x << endl;
	}
};
class B : public A {
public:
	void foo (int x = 200) {
		cout << "B::foo()：" << x << endl;
	}
};
int main (void) {
	B b;
	A* pa = &b;
	pa->foo ();
	return 0;
}
