#include <iostream>
using namespace std;
class Animal{
    public:
	string  name;
	int     age;
	public:
	Animal(string name="",int age=0)
		:name(name),age(age){
	    cout << "Animal()" << endl;
	}
	virtual  void  show()=0;
};
class Dog:public Animal{
    public:
	Dog(string name="",int age=0)
		:Animal(name,age){
	
	}
	void  show(){
	
	}	
};
int main(){
    // Animal  a;
	Dog  dog;
}



