#include <cstdlib>
#include <iostream>
using namespace std;
class A {
public:
	A (void) { cout << "A构造" << endl; }
	~A (void) { cout << "A析构" << endl; }
};
int main (void) {
	char* p1 = (char*)malloc (256);
	free (p1/*+128*/);
	A* p2 = new A[7];
	cout << *((int*)p2-1) << endl;
	delete[] p2;
//	delete p2;
	return 0;
}
