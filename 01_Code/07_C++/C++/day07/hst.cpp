#include <iostream>
using namespace std;
// 人类
class Human {
public:
	Human (string const& name, int age) :
		m_name (name), m_age (age) {
		cout << "Human构造：" << this << endl;
	}
	~Human (void) {
		cout << "Human析构：" << this << endl;
	}
	void eat (string const& food) {
		cout << "我在吃" << food << "。"
			<< endl;
	}
	void sleep (string const& loc) {
		cout << "我在" << loc << "睡觉。"
			<< endl;
	}
	void who (void) {
		cout << "我叫" << m_name << "，今年"
			<< m_age << "岁。" << endl;
	}
	string m_name;
	int m_age;
	void print (void) const {
		cout << "Hello, World !" << endl;
	}
private:
	int m_a;
public:
	int m_b;
protected:
	void set (int x) {
		m_a = x;
	}
	int m_c;
};
// 学生类
class Student : public Human {
public:
	Student (string const& name, int age,
		int no) : Human (name, age),
		m_no (no) {
		cout << "Student构造：" << this
			<< ' ' << &m_no << endl;
	}
	~Student (void) {
		cout << "Student析构：" << this
			<< endl;
	}
	void learn (string const& course) {
		cout << "我是学生，学号" << m_no
			<< "，我在学" << course << "。"
			<< endl;
	}
	int m_no;
	void foo (void) {
//		m_a = 100;
		set (100);
		m_b = 100;
		m_c = 100;
	}
};
// 教师类
class Teacher : public Human {
public:
	Teacher (string const& name, int age,
		float salary) : Human (name, age),
		m_salary (salary) {
		cout << "Teacher构造：" << this
			<< ' ' << &m_salary << endl;
	}
	~Teacher (void) {
		cout << "Teacher析构：" << this
			<< endl;
	}
	void teach (string const& course) {
		cout << "我是教师，一个月挣"
			<< m_salary << "，我在教"
			<< course << "。" << endl;
	}
	float m_salary;
	int print;
};
int main (void) {
	Student s1 ("张飞", 25, 1001);
	cout << s1.m_name << endl;
	cout << s1.m_age << endl;
	cout << s1.m_no << endl;
	s1.who ();
	s1.eat ("包子");
	s1.sleep ("地上");
	s1.learn ("C++");
	Teacher t1 ("赵云", 45, 20000);
	cout << t1.m_name << endl;
	cout << t1.m_age << endl;
	cout << t1.m_salary << endl;
	t1.who ();
	t1.eat ("火烧");
	t1.sleep ("沙发上");
	t1.teach ("C++");
	cout << sizeof (Human) << endl;
	cout << sizeof (Student) << endl;
	cout << sizeof (Teacher) << endl;
	Human* ph = &s1; // Is a ...
	cout << ph->m_name << endl;
	cout << ph->m_age << endl;
//	cout << ph->m_no << endl;
	ph->who ();
//	ph->learn ("UC");
	Student* ps = static_cast<Student*> (ph);
	cout << ps->m_no << endl;
	ps->learn ("UC");
	/* 导致风险
	Human h1 ("关羽", 30);
	ps = static_cast<Student*> (&h1);
	cout << ps->m_no << endl;
	ps->learn ("Win32");
	*/
	// 谨慎使用对象截切
	Human h1 = s1;
	cout << h1.m_name << endl;
	cout << h1.m_age << endl;
	h1.who ();
//	h1.m_c = 100;
	t1.Human::print ();
	return 0;
}
