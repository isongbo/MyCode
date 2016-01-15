#include <fstream>
#include <iostream>
using namespace std;
int main(){
    fstream  iofs("random.txt");
	if(!iofs){
	    cout << "open random failed" << endl; 
	}
	cout << "g=" << iofs.tellg() << "p=" 
		<< iofs.tellp() << endl;
	iofs << "hello";
	cout << "g=" << iofs.tellg() << "p=" 
		<< iofs.tellp() << endl;
	iofs  << 123;
	cout << "g=" << iofs.tellg() << "p=" 
		<< iofs.tellp() << endl;
	iofs.seekp(-4,ios::cur);
	iofs << "world";
    iofs.close(); 
}

