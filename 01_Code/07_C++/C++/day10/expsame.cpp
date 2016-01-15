#include <iostream>
using namespace std;
void foo (void) throw (int, double);
class A {
public:
	void bar (void) throw (char);
};
/*
void A::bar (void) throw () {}
*/
void A::bar (void) throw (char) {}
int main (void) {
	try {
		foo ();
	}
	catch (int ex) {
		cout << ex << endl;
	}
	return 0;
}
/*
void foo (void) throw (char) {
}
void foo (void) {
}
*/
void foo (void) throw (double, int) {
}
