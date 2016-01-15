#include <iostream>
using namespace std;
class A {
public:
	typedef unsigned int UINT;
	class B {};
	enum C {RED, GREEN, BLUE};
};
template<typename T>
void foo (void) {
	typename T::UINT u;
	typename T::B b;
	typename T::C c;
}
int main (void) {
	A::UINT u;
	A::B b;
	A::C c;
	foo<A> ();
	return 0;
}
