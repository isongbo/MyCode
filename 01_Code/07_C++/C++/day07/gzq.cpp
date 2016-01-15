#include <iostream>
using namespace std;
class A {
public:
	int* value (void) {
		return &m_a;
	}
private:
	int m_a;
};
class B : public A {};
int main (void) {
	cout << sizeof (B) << endl;
	B b;
	*b.value () = 1234;
//	b.m_a = 1234;
	cout << *b.value () << endl;
	return 0;
}
