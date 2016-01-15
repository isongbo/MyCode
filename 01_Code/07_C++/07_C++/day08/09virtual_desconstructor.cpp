#include <iostream>
using namespace std;
class Parent{
    public:
	Parent(){
	    cout << "Parent()" << endl;
	}	
	virtual ~Parent(){
	    cout << "~Parent()" << endl;
	}
	virtual  void  show(){
	    cout << "show()" << endl;
	}
};
class Child:public Parent{
    public:
	Child(){
	    cout << "Child()" << endl;
	}	
	~Child(){
	    cout << "~Child()" << endl;
	}
};
int main(){
    Parent  *pc=new Child();
	delete pc;
}



