#include <iostream>
using namespace std;
class Animal{
	int  x;
    public:
	Animal(){
	    cout << "Animal()" << endl;
	}	
	Animal(const Animal& a){
	    cout << "Animal(const Animal&)" 
			 << endl;
		x=a.x;
	}
    Animal&   operator=(const Animal& a){
	    cout << "operator=(const Animal)"
			 << endl;
		if(this!=&a){
		    x=a.x;
		}
		return *this;
	}
};
class Dog:public Animal{
    int *data;
	public:
	Dog(){           }
	Dog(const Dog& d):Animal(d){
	     cout << "Dog(const Dog&)" << endl;
	}
    Dog& operator=(const Dog& a){
		/* 通过父类名::operator= 区分*/
		Animal::operator=(a);
        cout << "operator=(const Dog&)" 
			 << endl;
	    if(this!=&a){
	       // 
		}
		return  *this;
	}
};
int main(){
    Dog  doga;
	// Dog  dogb=doga;
    Dog  dogb;
	dogb=doga;
}



