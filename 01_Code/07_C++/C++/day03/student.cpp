#include <iostream>
using namespace std;
// 学生
// 属性：姓名、年龄、学号
// 行为：学习、娱乐
/*class */struct Student {
public:
	// 构造函数
	Student (const string& name,
		int age, int no) {
		m_name = name;
		m_age = age;
		m_no = no;
	}
	Student (void) {
		m_name = "没名";
		m_age = 3;
		m_no = 1999;
	}
	// 学习
	void learn (string const& course) {
		cout << "我在学" << course << endl;
	}
	// 娱乐
	void play (string const& game) {
		cout << "我在玩" << game << endl;
	}
	// 自我介绍
	void who (void) {
		cout << "我叫" << m_name
			<< "，今年" << m_age
			<< "岁，我的学号是" << m_no
			<< endl;
	}
	void setName (string const& name) {
		if (name != "二")
			m_name = name;
	}
	void setAge (int age) {
		if (age >= 0)
			m_age = age;
	}
	void setNo (int no) {
		if (1000 < no && no < 2001)
		   m_no = no;
	}
	void foo (Student& student) {
		student.m_age++;
	}
private:
	string m_name; // 姓名
	int    m_age;  // 年龄
	int    m_no;   // 学号
};
int main (void) {
	Student sa ("张飞", 25, 1001);
	/*
	sa.setName ("张飞");
	sa.setAge (25);
	sa.setNo (1001);
	sa.setName ("二");
	sa.setAge (-10);
	sa.setNo (999);
	*/
	sa.who ();
	sa.learn ("C++");
	sa.play ("WOW");
	Student sc ("赵云", 22, 1002);
	/*
	sc.setName ("赵云");
	sc.setAge (22);
	sc.setNo (1002);
	*/
	sc.who ();
	sa.foo (sc);
//	sc.m_age++;
	sc.who ();
//	Student sd ();
	Student sd;
	sd.who ();
	Student* se = new Student ();
	se->who ();
	delete se;
	se = new Student ("关羽", 28, 1003);
	se->who ();
	delete se;
	return 0;
}
