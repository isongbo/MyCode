#include <iostream>
using namespace std;
void  printData(void * data){
    int *temp=static_cast<int*>(data);
	cout << *temp << endl;
}
int main(){
    int  x=100;
	printData(&x);
}

