#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
class A {
public:
	/*
	template<typename U>
	void foo (T t, U u) {
		cout << typeid (t).name () << ' '
			<< typeid (u).name () << endl;
	}
	*/
	template<typename U>
	void foo (T t, U u);
};
template<typename T>
	template<typename U>
void A<T>::foo (T t, U u) {
	cout << typeid (t).name () << ' '
		<< typeid (u).name () << endl;
}
int main (void) {
	A<int> a;
	a.foo (100, 3.14);
	return 0;
}
