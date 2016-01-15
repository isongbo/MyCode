#include <cstdio>
#include <iostream>
using namespace std;
class Student {
public:
	Student (string const& name) :
		m_name (name) {}
	void who (void) const {
		cout << "我是" << m_name << "。"
			<< endl;
	}
	static int add (int x, int y) {
		return x + y;
	}
	int m_age;
	double m_weight;
	string m_name;
};
int main (void) {
	string Student::*pname = &Student::m_name;
	printf ("%p\n", pname);
	Student s1 ("张飞"), s2 ("赵云");
	// .* : 成员指针解引用运算符
	cout << s1.*pname << "，"
		<< s2.*pname << endl;
	Student* ps1 = &s1, *ps2 = &s2;
	// ->* : 间接成员指针解引用运算符
	cout << ps1->*pname << "，"
		<< ps2->*pname << endl;
	void (Student::*pwho) (void) const =
		&Student::who;
	(s1.*pwho) ();
	(s2.*pwho) ();
	(ps1->*pwho) ();
	(ps2->*pwho) ();
	// 指向静态成员的指针与普通指针无异
	int (*padd) (int, int) = Student::add;
	cout << padd (123, 456) << endl;
	return 0;
}
