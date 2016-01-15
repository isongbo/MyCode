#include <iostream>
using namespace std;
int main(){
    const volatile int  x=100;
	int* px=const_cast<int*>(&x);
	*px=123;
	cout << *px << endl;
	cout <<  x  << endl;
}

