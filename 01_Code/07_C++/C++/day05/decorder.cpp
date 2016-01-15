#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
	int m_data;
};
class B {
public:
	B (void) {
		cout << "B构造" << endl;
	}
	~B (void) {
		cout << "B析构" << endl;
	}
private:
	A m_a;
};
int main (void) {
	B b;
	cout << sizeof (A) << endl;
	cout << sizeof (B) << endl;
	A a;
	A* p = &a;
	A& r = a;
	return 0;
}
