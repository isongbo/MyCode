#include <iostream>
using namespace std;
int main(){
    int  *pi=new int;
	cout << *pi << endl;
	*pi=100;
	cout << *pi << endl;
	delete pi;
	cout << *pi << endl;
	/* 申请一个double 类型对应的堆内存 */
    double  *pd=new double(1.5);
	cout << *pd << endl;
    *pd=22.5;
	cout << *pd << endl;
	delete pd;
	pd=NULL; 
}


