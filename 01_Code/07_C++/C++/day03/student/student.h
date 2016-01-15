// 声明学生类
#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
using namespace std;
// 学生类
class Student {
public:
	Student (string const& name, int age,
		int no);
	Student (void);
	inline void who (void);
	void learn (string const& course);
	void play (string const& game);
private:
	string m_name;
	int m_age;
	int m_no;
};
void Student::who (void) {
	cout << "我叫" << m_name
		<< "，今年" << m_age
		<< "岁，我的学号" << m_no << endl;
}
#endif // _STUDENT_H
