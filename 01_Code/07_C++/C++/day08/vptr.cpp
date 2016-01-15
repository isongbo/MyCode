#include <iostream>
using namespace std;
typedef void (*VFUN) (void*);
typedef VFUN* VPTR;
class A {
public:
	A (int data) : m_data (data) {
		VPTR vptr = *(VPTR*)this;
		cout << "A::A(int): " << vptr << "->["
			<< (void*)vptr[0] << ','
			<< (void*)vptr[1] << ']' << endl;
	}
	~A (void) {
		VPTR vptr = *(VPTR*)this;
		cout << "A::~A()  : " << vptr << "->["
			<< (void*)vptr[0] << ','
			<< (void*)vptr[1] << ']' << endl;
	}
	virtual void foo (void) {
		cout << "A::foo(void)：" << m_data
			<< endl;
	}
	virtual void bar (void) {
		cout << "A::bar(void)：" << m_data
			<< endl;
	}
protected:
	int m_data;
};
class B : public A {
public:
	B (int data) : A (data) {
		VPTR vptr = *(VPTR*)this;
		cout << "B::B(int): " << vptr << "->["
			<< (void*)vptr[0] << ','
			<< (void*)vptr[1] << ']' << endl;
	}
	~B (void) {
		VPTR vptr = *(VPTR*)this;
		cout << "B::~B()  : " << vptr << "->["
			<< (void*)vptr[0] << ','
			<< (void*)vptr[1] << ']' << endl;
	}
	void foo (void) {
		cout << "B::foo(void)：" << m_data
			<< endl;
	}
};
int main (void) {
	A a (100);
	VPTR vptr = *(VPTR*)&a;
	cout << "main()   : " << vptr << "->["
		<< (void*)vptr[0] << ','
		<< (void*)vptr[1] << ']' << endl;
	vptr[0] (&a);
	vptr[1] (&a);
	cout << "-----------------" << endl;
	B b (200);
	vptr = *(VPTR*)&b;
	cout << "main()   : " << vptr << "->["
		<< (void*)vptr[0] << ','
		<< (void*)vptr[1] << ']' << endl;
	vptr[0] (&b);
	vptr[1] (&b);
	cout << "-----------------" << endl;
	A& r = b;
	r.foo ();
//	vptr = *(VPTR*)&r;
//  根据函数名foo及其参数找到其在虚表中的下标
//	vptr[0] (&r);	
	cout << "-----------------" << endl;
	return 0;
}
