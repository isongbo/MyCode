#include <cstdlib>
#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A::A(void) this=" << this
			<< endl;
	}
	~A (void) {
		cout << "A::~A(void) this=" << this
			<< endl;
	}
	static void* operator new (size_t size) {
		void* p = malloc (size);
		cout << "A::new(size_t) p=" << p
			<< " size=" << size << endl;
		return p;
	}
	static void operator delete (void* p) {
		cout << "A::delete(void*) p=" << p
			<< endl;
		free (p);
	}
	static void* operator new[] (size_t size){
		void* p = malloc (size);
		cout << "A::new[](size_t) p=" << p
			<< " size=" << size << endl;
		return p;
	}
	static void operator delete[] (void* p) {
		cout << "A::delete[](void*) p=" << p
			<< endl;
		free (p);
	}
private:
	int m_i; // 4
	double m_d; // 8
	char m_c[12]; // 12
};
int main (void) {
	A* pa = new A;
	cout << "main(void) pa=" << pa << endl;
	// ...
	delete pa;
	cout << "----------------" << endl;
	pa = new A[3];
	cout << "main(void) pa=" << pa << endl;
	// ...
	cout << ((int*)pa)[-1] << endl;
	delete[] pa;
	return 0;
}
