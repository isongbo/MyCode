#include <iostream>
using namespace std;
class A{
	int  x;
    public:
	void  show(){
		/* this */
	    cout << "show()" << x << endl;
	}	
	static  void teststatic(){
	    cout << "test static() " << endl;
		/* 因为静态函数中无this */
		// cout << x << endl;
		// show();
		test2();
	}
	static  void  test2(){
	    cout << "test2()" << endl;
	}
};
int main(){
	A::teststatic();
    A   a;
	a.show();
}

