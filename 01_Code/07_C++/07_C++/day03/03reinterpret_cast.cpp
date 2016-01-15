#include <iostream>
using namespace std;
int main(){
    // int  x=0x10086;
	int  x=100;
    int  *p=reinterpret_cast<int*>(x);
	cout << p  << endl;
}

