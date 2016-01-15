#include <iostream>
using namespace std;
class A{
    int  x;
	int  y;
	public:
	A(int  x=0){  cout << "A(int)" << endl; }
	/* A(){ cout << "A()" << endl; } */
};
int main(){
    A    a;
	A    b(1);
    A    *pb=new A(2);
}

