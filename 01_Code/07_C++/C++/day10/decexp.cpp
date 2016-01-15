#include <iostream>
using namespace std;
class A {
public:
	void foo (void) {
		cout << "A::foo(void)" << endl;
		// ...
		throw -2;
	}
	~A (void) {
		cout << "A::~A(void)" << endl;
		// ...
		// throw -1;
		try {
			foo ();
		}
		catch (...) {}
	}
};
int main (void) {
	try {
		A a;
		a.foo ();
	}
	catch (int ex) {
		cout << ex << endl;
		return -1;
	}
	return 0;
}
