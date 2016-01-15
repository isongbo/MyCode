#include <iostream>
#include <typeinfo>
using namespace std;
namespace ns1 {
	class A {
	public:
		class B {
		public:
			class C {};
		};
	};
}
class Base {
	virtual void foo (void) {};
};
class Derived : public Base {
};
int main (void) {
	cout << typeid (char).name () << endl;
	cout << typeid (unsigned char).name ()
		<< endl;
	cout << typeid (short).name () << endl;
	cout << typeid (unsigned short).name ()
		<< endl;
	cout << typeid (int).name () << endl;
	cout << typeid (unsigned int).name ()
		<< endl;
	cout << typeid (long).name () << endl;
	cout << typeid (unsigned long).name ()
		<< endl;
	cout << typeid (long long).name ()
		<< endl;
	cout << typeid (unsigned long long).name()
		<< endl;
	cout << typeid (float).name () << endl;
	cout << typeid (double).name () << endl;
	cout << typeid (long double).name ()
		<< endl;
	cout << typeid (void).name () << endl;
	cout << typeid (bool).name () << endl;
	cout << typeid (int*).name () << endl;
	cout << typeid (int**).name () << endl;
	cout << typeid (int&).name () << endl;
	cout << typeid (float[4]).name () << endl;
	cout << typeid (char*[3]).name () << endl;
	cout << typeid (char(*)[3]).name ()
		<< endl;
	cout << typeid (short[2][3][4]).name ()
		<< endl;
	cout << typeid (
		char*(*)(short*,int*)).name ()
		<< endl;
	struct Student {
		char name[128];
		int age;
	};
	cout << typeid (Student).name () << endl;
	cout << typeid (ns1::A::B::C).name ()
		<< endl;
	Derived d;
	Base* p = &d;
	cout << typeid (*p).name () << endl;
	Base& r = d;
	cout << typeid (r).name () << endl;
	return 0;
}
