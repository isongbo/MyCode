#include <iostream>
using namespace std;
class A {};
class B : public A {};
class Base {
public:
	void aaa (void) {
		cout << "Base::aaa(void)" << endl;
	}
	virtual void bbb (void) {
		cout << "Base::bbb(void)" << endl;
	}
	virtual void ccc (void) {
		cout << "Base::ccc(void)" << endl;
	}
	virtual A* ddd (void) {
		cout << "Base::ddd(void)" << endl;
		return NULL;
	}
	virtual void eee (void) {
		cout << "Base::eee(void)" << endl;
	}
};
class Derived : public Base {
public:
	virtual void aaa (void) {
		cout << "Derived::aaa(void)" << endl;
	}
	void bbb (int x) {
		cout << "Derived::bbb(int)" << endl;
	}
	void bbb (void) const {
		cout << "Derived::bbb(void)const"
			<< endl;
	}
	void bbb (void) {
		cout << "Derived::bbb(void)" << endl;
	}
	/* 和基类中的ccc函数构成不正当关系
	int ccc (void) {
		cout << "Derived::ccc(void)" << endl;
	}*/
	B* ddd (void) {
		cout << "Derived::ddd(void)" << endl;
		return NULL;
	}
private:
	void eee (void) {
		cout << "Derived::eee(void)" << endl;
	}
};
int main (void) {
	Derived d;
	Base& b = d;
	b.aaa ();
	b.bbb ();
	b.ddd ();
	b.eee ();
	return 0;
}
