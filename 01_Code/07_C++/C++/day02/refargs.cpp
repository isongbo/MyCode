#include <iostream>
using namespace std;
struct Student {
	char name[256];
	char info[4096];
};
// 常引用型参数防止对所引用实参变量的意外修改
void print (Student const& student) {
	cout << "姓名：" << student.name << endl;
	cout << "简历：" << student.info << endl;
//	*student.name = '\0';
}
// 常左值引用型的形参既可以接受左值形式的实参
// 也可以接受右值形式的实参，谓之万能引用
int add (const int& x, int const& y) {
	return x + y;
}
int main (void) {
	Student student = {"张飞", "达内学生"};
	print (student);
	print (student);
	int x = 123, y = 456;
	// 左值形式的实参
	cout << add (x, y) << endl;
	// (纯)右值形式的实参
	cout << add (123, 456) << endl;
	// (将亡)右值形式的实参
	cout << add (x + y, x - y) << endl;
//	x + y = 10;
	return 0;
}
