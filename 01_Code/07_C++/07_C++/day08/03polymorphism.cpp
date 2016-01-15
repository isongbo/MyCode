#include <iostream>
using namespace std;
class Animal{
    public:
	void  show(){
	    cout << "animal show()" << endl;
	}	
	virtual  void run(){
	    cout << "animal run()" << endl;
	}
};
class Fish:public Animal{
    public:
	void  show(){
	    cout << "fish show()" << endl;
	}	
	virtual void  run(){
	    cout << "鱼在水中游" << endl; 
	}
};
class Bird:public Animal{
    public:
    void  show(){
	    cout << "bird show()" << endl;
	}
	void  run(){
	    cout << "鸟在空中飞" << endl;
	}
};
int main(){
    Bird  bird;
	Fish  fish;
    bird.show();
	bird.run();
	fish.show();
	fish.run();
    Animal  *pa=&bird;
	pa->show();
	pa->run();
    Animal  ta=fish;
	ta.show();
	ta.run();
    Animal  &ra=fish;
	ra.show();
	ra.run();
}




