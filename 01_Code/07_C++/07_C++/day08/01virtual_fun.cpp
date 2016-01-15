#include <iostream>
using namespace std;
class A{
	public:
	void  *ptr;
    int   x;
	int   y;
    A(int x=0,int y=1):x(x),y(y){
	
	}
	// virtual void  show(){   }
};
int main(){
    A   a(1,12);
    int *pm=reinterpret_cast<int*>(&a);
	cout << *pm << endl;
    cout << *(pm+1) << endl;
    cout << *(pm+2) << endl;
}


