// 使用学生类创建对象
#include "student.h"
int main (void) {
	// 栈，单个对象，有参构造
	Student sa ("张飞", 25, 1001);
	sa.who ();
	sa.learn ("C++");
	sa.play ("英雄联盟");
	// 堆，单个对象，无参构造
	Student* sc = new Student;
	sc->who ();
	delete sc;
	// 栈，对象数组，无参构造
	Student ss[3];
	for (int i = 0; i < 3; ++i)
		ss[i].who ();
	// 栈，对象数组，有参构造
	Student st[3] = {
		Student ("关羽", 40, 1002),
		Student ("赵云", 22, 1003),
		Student ("刘备", 35, 1004)};
	for (int i = 0; i < 3; ++i)
		st[i].who ();
	// 堆，对象数组，无参构造
	Student* su = new Student[3];
	for (int i = 0; i < 3; ++i)
		su[i].who ();
	delete[] su;
	// 堆，对象数组，有参构造
	Student* sv = new Student[3] {
		Student ("关羽", 40, 1002),
		Student ("赵云", 22, 1003),
		Student ("刘备", 35, 1004)};
	for (int i = 0; i < 3; ++i)
		sv[i].who ();
	delete[] sv;
	return 0;
}
