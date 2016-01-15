#include <iostream>
using namespace std;
class A {
public:
	template<typename T>
	T foo (void) const {
		T t;
		return t;
	}
};
template<typename T>
void bar (T const& t, T const* p) {
	cout << t.template foo<int> () << endl;
	cout << p->template foo<int> () << endl;
}
int main (void) {
	A a;
	cout << a.foo<int> () << endl;
	bar (a, &a);
	return 0;
}
