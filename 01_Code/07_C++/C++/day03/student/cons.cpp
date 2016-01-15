// 实现学生类的构造函数
#include "student.h"
Student::Student (string const& name, int age,
	int no) {
	m_name = name;
	m_age = age;
	m_no = no;
}
Student::Student (void) {
	m_name = "没名";
	m_age = 3;
	m_no = 1999;
}
