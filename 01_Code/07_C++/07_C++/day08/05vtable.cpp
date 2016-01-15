#include <iostream>
using namespace std;
class  Animal{
    public:
	/* int* ptr; */	
	int*   x;
	void  show(){
	    cout << "this is animal show" << endl;
	}	
	virtual void run(){
	    cout << "animal run" << endl; 
	}  
	virtual void fun(){
	    cout << "animal fun" << endl;
	}
};
class Dog:public Animal{
    public:
    void  fun(){
	    cout << "看家" << endl;
	}
};
class Cat:public Animal{
    public:
	void  fun(){
	    cout << "抓老鼠" << endl;
	}	
    void  run(){
	    cout << "猫走猫步" << endl;
	}
};
#include <cstring>
int main(){
    Dog   doga;
	Cat   cata;
	Animal  *pa=&doga;
	memcpy(&doga,&cata,4);
	pa->fun();
    doga.fun();
}



