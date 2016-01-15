#include <iostream>
using namespace std;
class Account {
public:
	Account (string const& name, int no,
		double balance) : m_name (name),
		m_no (no), m_balance (balance) {}
	void save (double money) {
		m_balance += money;
	}
	void draw (double money) {
		if (money > m_balance) {
			cout << "余额不足！" << endl;
			return;
		}
		m_balance -= money;
	}
	void query (void) const {
		cout << "户名：" << m_name << endl;
		cout << "账号：" << m_no << endl;
		cout << "余额：" << m_balance << endl;
	}
	void settle (void) {
		// 非静态成员函数可以访问静态成员
		m_balance *= (1 + m_rate / 100);
		adjust (m_rate);
	}
	// 静态成员函数
	static void adjust (double rate) {
		if (rate > 0)
			m_rate = rate;
		// 静态成员函数不能访问非静态成员
//		cout << m_no << endl;
//		settle ();
	}
private:
	string m_name;
	int m_no;
	double m_balance;
	// 声明静态成员变量
	static double m_rate;
public:
	// 只有常静态成员变量可以在类内直接初始化
	static const int m_n = 1234;
};
// 定义静态成员变量
double Account::m_rate = 0.5;
//const int Account::m_n = 1234;
int main (void) {
	Account acc1 ("张飞", 1001, 1000);
	acc1.save (2000);
	acc1.draw (500);
	acc1.query ();
	Account acc2 ("赵云", 1002, 10000);
	acc2.save (20000);
	acc2.draw (5000);
	acc2.query ();
	cout << "-----------------" << endl;
//	acc1.adjust (1.0);
//	acc2.adjust (1.0);
	Account::adjust (1.0);
	// 静态成员同样受作用域和访控属性的约束
//	Account::m_rate = 1.0;
	acc1.settle ();
	acc2.settle ();
	acc1.query ();
	acc2.query ();
	cout << Account::m_n << endl;
	return 0;
}
