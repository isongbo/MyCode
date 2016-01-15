#include <iostream>
using namespace std;
class  A{
	double   x;
    public:
	A(){
	    cout << "A()" << endl;
	}	
	~A(){
        cout << "~A()" << endl;	
	}
};
void  foo(){
    // A* pa=new A[5];
    // delete[] pa;
	A    a;
	A    *b=new A();
// 	b->~A();
	delete  b;
}
int main(){
	foo();
}

