#include <iostream>
using namespace std;
class A {
public:
	A (int data = 0) : m_data (data) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
	int m_data;
};
class PA {
public:
	PA (A* pa = NULL) : m_pa (pa) {}
	~PA (void) {
		if (m_pa) {
			delete m_pa;
			m_pa = NULL;
		}
	}
	A& operator* (void) const {
		return *m_pa;
	}
	A* operator-> (void) const {
		return &**this;
	}
private:
	A* m_pa;
};
int main (void) {
	/*
	A* pa = new A (1234);
	(*pa).m_data = 5678;
	cout << pa->m_data << endl;
	delete pa;
	*/
	PA pa (new A (1234));
	(*pa).m_data = 5678;
//	pa.operator* ().m_data = 5678;
	cout << pa->m_data << endl;
//	cout << pa.operator-> ()->m_data << endl;
	return 0;
}
