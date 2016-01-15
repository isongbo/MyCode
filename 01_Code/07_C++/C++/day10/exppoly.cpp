#include <iostream>
using namespace std;
class Base {
public:
	virtual ~Base (void) throw () {}
	virtual int foo (int, double) const
		throw (char, short, int) = 0;
	virtual void bar (void) throw () = 0;
};
class Derived : public Base {
public:
	~Derived (void) throw () {}
	int foo (int, double) const
		throw (int, short, char) {}
//	int foo (int, double) const
//		throw (int, short) {}
	/* 放松了基类的异常限定
	int foo (int, double) const
		throw (double) {}
	*/
//	void bar (void) {}
	void bar (void) throw () {}
};
int main (void) {
	Derived d;
	return 0;
}
