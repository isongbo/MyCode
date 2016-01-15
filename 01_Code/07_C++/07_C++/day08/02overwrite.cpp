#include <iostream>
using namespace std;
class  Animal{
    public:
	void  show(){
	    cout << "this is animal show" << endl;
	}	
	virtual  void run(){
	    cout << "animal run" << endl;
	}
	virtual  void run(int s){
	    cout << "run as" << s << "km/h" 
			 << endl;
	}
};
class Dog:public Animal{
    public:
	/* 名字隐藏 namehide */	
	void  show(){
	    cout << "this is dog show" << endl;
	}	
	/* 一虚则全虚 函数重写 overwrite */
    void  run(){
	    cout << "this is dog run" << endl;
	}
};
int main(){
    Animal  a;
	cout << sizeof a << endl;
	a.run();
	a.run(45);
	cout << "-------------" << endl;
    Animal  *pa=new Dog();
	pa->show();
	pa->run();
}


