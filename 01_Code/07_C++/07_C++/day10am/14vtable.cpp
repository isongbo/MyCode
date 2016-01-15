#include <iostream>
using namespace std;
class  A{
    public:
	void  show(){
	    cout << "show()" << endl;
	}	
	virtual  void run(int s){
	    cout << "run()" << s << endl;
	}
	virtual  void fun(int x){
	    cout << "fun()" << x << endl;
	}
};
typedef  void  (*FUN)(A* mythis,int s);
typedef  FUN*  VTABLE;
int main(){
    A   a;
    VTABLE  vt=*((VTABLE*)&a);
	vt[0](&a,100);
	vt[1](&a,200);
}


