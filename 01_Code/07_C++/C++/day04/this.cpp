#include <iostream>
using namespace std;
class User {
public:
	User (string const& name, int age) :
		m_name (name), m_age (age) {
		cout << "构造 : " << this << endl;
	}
	void print (void) {
		cout << "print : " << this << endl;
		cout << m_name << ' '
			<< m_age << endl;
	}
private:
	string m_name;
	int m_age;
};
/*
void _ZN4User5printEv (User* this) {
	cout << this->m_name << ' '
		<< this->m_age << endl;
}
*/
class A {
public:
//	A (int data) : data (data) {}
	A (int data) {
		this->data = data;
	}
	int data;
};
class B {
public:
	B (int cn = 0) : m_cn (cn) {}
	B& inc (void) {
		++m_cn;
		return *this; // 返回自引用
	}
	/*
	B inc (void) {
		++m_cn;
		return *this; // 返回自拷贝
	}*/
	int m_cn;
};
int main (void) {
	User user1 ("张飞", 22);
	User user2 ("赵云", 20);
	cout << sizeof (user1) << ' '
		<< sizeof (user2) << endl;
	cout << "main : " << &user1 << endl;
	user1.print ();
	/*
	_ZN4User5printEv (&user1);
	*/
	cout << "main : " << &user2 << endl;
	user2.print ();
	/*
	_ZN4User5printEv (&user2);
	*/
	A a (1234);
	cout << a.data << endl;
	B b;
	b.inc ().inc ().inc ();
	cout << b.m_cn << endl; // 3
}
