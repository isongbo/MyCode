#include <iostream>
using namespace std;
void print (int money) {
	cout << __LINE__ << ": "
		<< money << endl;
}
namespace abc {
	int balance = 0;
	void save (int money) {
		balance += money;
	}
}
namespace abc {
	void draw (int money) {
		balance -= money;
	}
	void print (int money) {
		cout << __LINE__ << ": "
			<< money << endl;
	}
	void show (void) {
		::print (balance);
	}
}
namespace ccb {
	int balance = 0;
	void save (int money) {
		balance += money;
	}
	void draw (int money);
	void show (void) {
		cout << balance << endl;
	}
}
void ccb::draw (int money) {
	balance -= money;
}
namespace ns1 {
	int x = 1;
	namespace ns2 {
		int x = 12;
		namespace ns3 {
			int x = 123;
			namespace ns4 {
				int x = 1234;
			}
		}
	}
}
int main (void) {
	abc::save (5000);
	cout << abc::balance << endl;
	abc::draw (3000);
	cout << abc::balance << endl;
	ccb::save (8000);
	cout << ccb::balance << endl;
	ccb::draw (2000);
	cout << ccb::balance << endl;
	using namespace ccb; // 名字空间指令
	show ();
	using abc::show; // 名字空间声明
	show ();
	cout << ns1::x << endl;
	cout << ns1::ns2::x << endl;
	cout << ns1::ns2::ns3::x << endl;
	cout << ns1::ns2::ns3::ns4::x << endl;
	using namespace ns1::ns2::ns3::ns4;
	cout << x << endl;
	// 名字空间别名
	namespace ns_four = ns1::ns2::ns3::ns4;
	cout << ns_four::x << endl;
	return 0;
}
