#include <iostream>
using namespace std;
class Base {
public:
	Base (void) : m_array (new int[10]) {
		cout << "基类构造" << endl;
	}
	~Base (void) {
		cout << "基类析构" << endl;
		delete[] m_array;
	}
private:
	int* m_array;
};
class Derived : public Base {
public:
	Derived (void) :
		m_buffer (new char[256]) {
		cout << "子类构造" << endl;
	}
	~Derived (void) {
		cout << "子类析构" << endl;
		delete[] m_buffer;
	}
private:
	char* m_buffer;
};
int main (void) {
	/*
	Derived* pd = new Derived;
	delete pd;
	*/
	Base* pb = new Derived;
//	delete pb; // 导致子类的特有部分形成泄漏
	delete static_cast<Derived*> (pb);
	return 0;
}
