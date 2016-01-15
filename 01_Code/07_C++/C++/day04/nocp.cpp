#include <iostream>
using namespace std;
class NoCopy {
public:
	NoCopy (string const& name) {
		m_name = name;
	}
	string m_name;
private:
	// 通过将拷贝构造函数私有化，防止对象被
	// 复制
	NoCopy (NoCopy const&);
};
int main (void) {
	NoCopy nc1 ("Hello, C++ !");
	cout << nc1.m_name << endl;
	NoCopy nc2 (nc1);
	cout << nc2.m_name << endl;
	return 0;
}
