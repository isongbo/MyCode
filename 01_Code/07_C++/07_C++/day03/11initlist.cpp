#include <iostream>
using namespace std;
class  A{
    const  int  x;
	int   y;
	int&  z;
	public:
	A(int  pz=0,int y=1):x(100),y(y),
	    z(*(new int(pz))){
	    // x=100;
		// y=y;
	}
};
int main(){
    A   a;
}

