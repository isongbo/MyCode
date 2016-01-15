#include <iostream>
using namespace std;
class Animal{
    public:
	Animal(){
	    cout << "Animal()" << endl;
	}	
	Animal(int a){
	    cout << "Animal(int)" << endl;
	}
	~Animal(){
	    cout << "~Animal()" << endl;
	}
};
class  Dog:public Animal{
    public:
	Dog(int  a=0):Animal(a){ 
	   cout << "Dog()" << endl; 
	}	
	~Dog(){
	    cout << "~Dog()" << endl;
	}
};
class ZongShi:public Dog{
    public:
	ZongShi(){
	    cout << "ZongShi()" << endl;
	}	
	~ZongShi(){
	    cout << "~ZongShi()" << endl; 
	}
}; 
int main(){
    // Dog  dog;
	ZongShi  zs;
}


