#include <iostream>
using namespace std;
class  A{
    public:
	static  void  show(){
	    cout << "static A show()" << endl;
	}	
	static  int   x;
};
int  A::x=1;
class B:public A{
    public:
	static  void  show(){
	    cout << "static B show()" << endl;
	}
	static  int  x;
};
int  B::x=100;
int main(){
    B::show();
    B::A::show();
	A::show();
	cout << A::x << endl;
	cout << B::x << endl;
	B::x=123;
	B::A::x=10001;
	cout << A::x << endl;
	cout << sizeof(B) << endl;
}

