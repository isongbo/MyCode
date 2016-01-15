#include <cstdio>
#include <cstring>
#include <errno.h>
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
template<typename T>
class AutoPtr {
public:
	AutoPtr (T* p = NULL) : m_p (p) {}
	AutoPtr (AutoPtr& that) :
		m_p (that.release ()) {}
	AutoPtr& operator= (AutoPtr& rhs) {
		if (&rhs != this)
			reset (rhs.release ());
		return *this;
	}
	~AutoPtr (void) {
		if (m_p) {
			delete m_p;
			m_p = NULL;
		}
	}
	T& operator* (void) const {
		return *m_p;
	}
	T* operator-> (void) const {
		return &**this;
	}
private:
	T* release (void) {
		T* p = m_p;
		m_p = NULL;
		return p;
	}
	void reset (T* p) {
		if (p != m_p) {
			delete m_p;
			m_p = p;
		}
	}
	T* m_p;
};
template<typename T>
class AutoPtr<T[]> {
public:
	AutoPtr (T* p = NULL) : m_p (p) {}
	AutoPtr (AutoPtr& that) :
		m_p (that.release ()) {}
	AutoPtr& operator= (AutoPtr& rhs) {
		if (&rhs != this)
			reset (rhs.release ());
		return *this;
	}
	~AutoPtr (void) {
		if (m_p) {
			delete[] m_p;
			m_p = NULL;
		}
	}
	T& operator* (void) const {
		return *m_p;
	}
	T* operator-> (void) const {
		return &**this;
	}
private:
	T* release (void) {
		T* p = m_p;
		m_p = NULL;
		return p;
	}
	void reset (T* p) {
		if (p != m_p) {
			delete[] m_p;
			m_p = p;
		}
	}
	T* m_p;
};
void bar (void) {
	AutoPtr<A> pa (new A (100));
	pa->m_data++;
//	pa.operator->()->m_data++;
	cout << (*pa).m_data << endl;
//	cout << pa.operator*().m_data << endl;
	AutoPtr<A> pb = pa;
	cout << pb->m_data << endl;
	AutoPtr<A> pc (new A (200));
	pb = pc;
	cout << pb->m_data << endl;
	AutoPtr<A[]> pd (new A[1]);
	FILE* fp = fopen ("none", "r");
	if (! fp)
		throw string (strerror (errno));
	// ...
}
int main (void) {
	try {
		bar ();
	}
	catch (string& ex) {
		cout << ex << endl;
		return -1;
	}
	return 0;
}
// C++2011：smart_ptr<T>
