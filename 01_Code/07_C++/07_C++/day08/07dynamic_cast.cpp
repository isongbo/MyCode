#include <iostream>
#include <typeinfo>
using namespace std;
class  Parent{
    public:
	virtual  void  run(){  }	
};
class ChildA:public Parent{

};
class ChildB:public Parent{

};
int main(){
    Parent *pa=new ChildA();
    if(dynamic_cast<ChildA*>(pa)){
	     cout << "pa 指向ChildA" << endl;
	}
	if(typeid(*pa)==typeid(ChildB)){
	    cout << "pa 指向ChildB" << endl;
	}
}

