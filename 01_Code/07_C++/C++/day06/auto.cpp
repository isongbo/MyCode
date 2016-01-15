#include <iostream>
#include <memory>
using namespace std;
class Student {
public:
	Student (string const& name = "",
		int age = 0) :
		m_name (name), m_age (age) {
		cout << "Student构造" << endl;
	}
	~Student (void) {
		cout << "Student析构" << endl;
	}
	string m_name;
	int m_age;
};
void foo (void) {
	auto_ptr<Student> ps (new Student (
		"张飞", 25));
	cout << (*ps).m_name << "，"
		<< ps->m_age << endl;
}
void bar (auto_ptr<Student> ps) {
	cout << ps->m_name << endl;
}
int main (void) {
	for (int i = 0; i < 5; ++i)
		foo ();
	auto_ptr<Student> p1 (new Student (
		"赵云", 22));
	auto_ptr<Student> p2;
	// 智能指针没有复制语义，只有转移语义
	p2 = p1;
	cout << p2->m_name << endl;
//	cout << p1->m_name << endl;
	bar (p2);
//	cout << p2->m_name << endl;
	// 不能用智能指针管理对象数组
//	auto_ptr<Student> p3 (new Student[2]);
	return 0;
}
