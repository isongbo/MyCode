#include <iostream>
using namespace std;
template<typename T>
class A {
public:
	virtual void foo (T const& t) const {
		cout << "A::foo" << endl;
	}
};
template<typename T>
class B : public A<T> {
public:
	void foo (T const& t) const {
		cout << "B::foo" << endl;
	}
};
class C {
public:
	template<typename T>
	/*virtual */void foo (T const& t) const {
		cout << "C::foo" << endl;
	}
};
int main (void) {
	B<int> b;
	A<int>& a = b;
	a.foo (0);
	return 0;
}
