// 实现学生类的成员函数
#include <iostream>
using namespace std;
#include "student.h"
void Student::learn (string const& course) {
	cout << "我在学" << course << endl;
}
void Student::play (string const& game) {
	cout << "我在玩" << game << endl;
}
