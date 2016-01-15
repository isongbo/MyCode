#include <iostream>
using namespace std;
class  A{
    public:
	A(){
	    cout << "A() this=" << this << endl;
	}
	void  show(){
	    cout << "show() this=" << this 
			 << endl;
	}
};
int main(){
    A   a;
	cout << "&a=" << &a << endl;
	a.show();
	A   b;
	b.show();
}


