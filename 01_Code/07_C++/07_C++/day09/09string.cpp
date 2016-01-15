#include <iostream>
#include <string>
using namespace std;
int main(){
    string  stra("hello");
	string  strb="hello";
    if(stra==strb){
	    cout << "相等" << endl;  
	}
	stra="";
	cout << "stra=" << stra << endl;
	stra="test";
    stra+=strb;
	stra=stra+"test";
	cout << stra << endl;
	string name="hello";
	int    age=23;
	double salary=8878.85;
    /* sprintf()  */
}

