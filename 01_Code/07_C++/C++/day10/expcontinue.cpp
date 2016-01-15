#include <iostream>
#include <memory>
using namespace std;
class A {
public:
	A (void) { cout << "A构造" << endl; }
	~A (void) { cout << "A析构" << endl; }
};
void bar (void) {
	// ...
	throw -1;
	// ...
}
void foo (void) {
	/*
	A* a = new A;
	try {
		bar ();
		delete a;
	}
	catch (int ex) {
		// ...
		delete a;
		throw;
	}
	*/
	auto_ptr<A> a (new A);
	bar ();
}
int main (void) {
	try {
		foo ();
	}
	catch (int ex) {
		cout << ex << endl;
	}
	return -1;
}
