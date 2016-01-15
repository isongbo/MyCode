#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;
int main(){
    int  *pi=
	  static_cast<int*>(malloc(0xffffffff));
	cout << "pi=" << pi << endl;
	free(pi);
	try{
	int  *pi2=new int[0xffffffff];
	cout << "pi2=" << pi2 << endl;
	}catch(bad_alloc& e){
	cout << "have exception" << endl;
	cout << e.what() << endl;
	}
    string  mystr("hello");
	cout << mystr[1] << endl;
	cout << mystr.at(1) << endl;
	cout << mystr[15] << endl;
	/* #include <stdexcept> */
	try{
	cout << mystr.at(15) << endl;
	}catch(out_of_range& e){
    cout << e.what() << endl;	
	}
}



