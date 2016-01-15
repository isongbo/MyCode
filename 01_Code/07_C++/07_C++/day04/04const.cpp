#include <iostream>
using namespace std;
class A{
	int  x;
	mutable int  y;
    public:
	A(){    }
	void  data()const{
	    cout << x << endl; 
	}
	/* _ZNK1A4showEv */
	void  show()const{
	    cout << "show()const" << endl;
		// x=101;
		y=101;
		cout << x << '/' << y << endl;
		data();
	}
	/* _ZN1A4showEv */
	void  show(){
	    cout << "show()" << endl;
	}
};
int main(){
    A   a;
	const A   b;
	a.show();
	b.show();
}

