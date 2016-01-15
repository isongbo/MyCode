#include <iostream>
using namespace std;
void  printInt(const int  x){
    cout << x << endl;
}
void  printInt2(const int& x){
    cout << x << endl;
}
int main(){
    const int&  rx=10;
    printInt(100);
	int  x=101;
	printInt(x);
	printInt2(x);
	printInt2(100);
}

