#include <iostream>
using namespace std;
class A{
    public:
	int   x;
	public:
	A(int x=0):x(x){
	}
	void  show(){
	    cout << "A show()" << endl;
	}
};
class B:public A{
    public:
	int  x;
	void  show(){
		A::show();
	    cout << "B show()" << endl;
	}	
};
int main(){
    B   b;
    b.show();
	b.A::show();
	b.x=100;
	b.A::x=101;
    cout << sizeof b << endl;
}






