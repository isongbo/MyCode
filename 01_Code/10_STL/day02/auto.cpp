#include <cstdio>
#include <cstring>
#include <errno.h>
#include <iostream>
#include <memory>
using namespace std;
class A {
public:
	A (int data = 0) : m_data (data) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
	int m_data;
};
void foo (void) {
	A* pa = new A (100);
	pa->m_data++;
	cout << (*pa).m_data << endl;
	// ...
	FILE* fp = fopen ("none", "r");
	if (! fp)
		throw string (strerror (errno));
	// ...
	delete pa;
}
void hum (auto_ptr<A> pa) {}
void bar (void) {
	/*
	auto_ptr<A> pa (new A (100));
	pa->m_data++;
	cout << (*pa).m_data << endl;
	auto_ptr<A> pb = pa;
	cout << pb->m_data << endl;
//	cout << pa->m_data << endl;
//	hum (pb);
//	cout << pb->m_data << endl;
	*/
	auto_ptr<A> pc (new A[3]);
	// ...
	FILE* fp = fopen ("none", "r");
	if (! fp)
		throw string (strerror (errno));
	// ...
}
int main (void) {
	try {
//		foo ();
		bar ();
	}
	catch (string& ex) {
		cout << ex << endl;
		return -1;
	}
	return 0;
}
