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
int main(){
    Animal  a;
    a.x=reinterpret_cast<int*>(0x100);
    int* pm=reinterpret_cast<int*>(&a);
	cout << hex << "虚表地址:" 
		 << *pm << endl; 
    cout << *(pm+1) << endl;
	Animal  b;
    /* 获取第二个对象的虚表地址 */
	int* ptr=reinterpret_cast<int*>(&b);
    cout << "虚表地址:" << *(ptr+0) << endl;
    Dog   doga;
    ptr=reinterpret_cast<int*>(&doga);
    cout << "doga 虚表" << *ptr << endl;
	Dog   dogb;
    ptr=reinterpret_cast<int*>(&dogb);
    cout << "dogb 虚表" << *ptr << endl;
    Animal  *pa;    
    Animal  aa;
	Cat     cata;
	int  x;
	cin >> x;
	if(x){
	    pa=new Dog();
		aa=doga;
	}else{
	    pa=new Cat();
		aa=cata;
	}
	pa->fun();
	aa.fun();
	doga.fun();
}



