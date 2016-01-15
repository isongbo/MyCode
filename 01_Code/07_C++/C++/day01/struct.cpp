#include <iostream>
using namespace std;
struct Student {
	// 成员变量
	char name[256];
	int age;
	// 成员函数
	void who (void) {
		cout << "我是" << name << "，今年"
			<< age << "岁。" << endl;
	}
};
int main (void) {
	/*struct */Student student = {"张飞", 25};
	cout << student.name << "，"
		<< student.age << endl;
	student.who (); // 直接成员访问
	Student* ps = &student;
	ps->who (); // 间接成员访问
	return 0;
}
