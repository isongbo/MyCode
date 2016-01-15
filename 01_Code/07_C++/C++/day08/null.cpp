#include <iostream>
using namespace std;
class Dummy {
public:
	void foo (void) {
		cout << "Dummy::foo(void)" << endl;
//		m_data = 0;
	}
//	void _ZN5Dummy3fooEv (Dummy* this) {
//		this->m_data = 0;
//	}
private:
	int m_data;
};
int main (void) {
	Dummy* p = NULL;
	p->foo ();
//	_ZN5Dummy3fooEv (p);
	return 0;
}
