#include <iostream>
using namespace std;
class  A{
	int   x;
    public:
	void  show(){
	    cout << "show()" << x << endl;
	}	
	/* 线程封装  */
	static  void  callshow(A* mythis){
	    mythis->show();
	}
};
int main(){
	A  a;
    A::callshow(&a);
}

