#include <iostream>
using namespace std;
// 爷爷
class A {
public:
	// 动态类型转换只能用于多态继承
	virtual void foo (void) {}
};
// 爸爸
class B : public A {};
// 孙孙
class C : public B {};
// 街坊
class D {};
int main (void) {
	B b;
	A* pa = &b; // B is a A —— 皆然性
	cout << "pa = " << pa << endl;
	cout << "动态类型转换" << endl;
	// pa实际指向B类对象，转换成功
	B* pb = dynamic_cast<B*> (pa);
	cout << "pb = " << pb << endl;
	// pa没有指向C类对象，转换失败，安全
	C* pc = dynamic_cast<C*> (pa);
	cout << "pc = " << pc << endl;
	try {
		A& ra = b;
		C& rc = dynamic_cast<C&> (ra);
	}
	catch (exception& ex) {
		cout << ex.what () << endl;
	}
	// pa没有指向D类对象，转换失败，安全
	D* pd = dynamic_cast<D*> (pa);
	cout << "pd = " << pd << endl;
	cout << "静态类型转换" << endl;
	// B是A的子类，转换成功
	pb = static_cast<B*> (pa);
	cout << "pb = " << pb << endl;
	// C是A的孙子类，转换成功，危险
	pc = static_cast<C*> (pa);
	cout << "pc = " << pc << endl;
	// D和A没有继承关系，转换失败，安全
//	pd = static_cast<D*> (pa);
//	cout << "pd = " << pd << endl;
	cout << "重解释类型转换" << endl;
	// 编译期、运行期均不做检查，永远成功，
	// 最危险
	pb = reinterpret_cast<B*> (pa);
	cout << "pb = " << pb << endl;
	pc = reinterpret_cast<C*> (pa);
	cout << "pc = " << pc << endl;
	pd = reinterpret_cast<D*> (pa);
	cout << "pd = " << pd << endl;
	return 0;
}
