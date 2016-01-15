#include <iostream>
#include <typeinfo>
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
	string  name;
	int  *data;
	Dog(){
	     data=new int(0);
	}
    void  fun(){
	    cout << "看家" << endl;
	}
	void  run(){
	    cout << "狗用四条腿狂奔" << endl;
	}
	void  dogfun(){
		*data=100;
		cout << name << endl;
	    cout << "用来辅助办案" << endl;
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
	void  catfun(){
	    cout << "喵星人卖萌" << endl;
	}
};
#include <cstring>
void  testAnimal(Animal* animal){
    animal->run();
	/* 是Dog  就调用 dogfun  是Cat 就调用
	   catfun */
	// ((Dog*)animal)->dogfun();
	/* 恢复个性 
    if(typeid(Dog)==typeid(*animal)){
	    ((Dog*)animal)->dogfun();
	}
	if(typeid(Cat)==typeid(*animal)){
	    ((Cat*)animal)->catfun();
	} */
	if(dynamic_cast<Dog*>(animal)){
	    ((Dog*)animal)->dogfun();
	}
    if(dynamic_cast<Cat*>(animal)){
	    ((Cat*)animal)->catfun(); 
	}
}
int main(){
    Dog   doga;
	doga.name="test";
	Cat   cata;
	testAnimal(&cata);
	testAnimal(&doga);
	Animal *pa=new Dog();
    cout << typeid(pa).name() << endl;
	cout << typeid(*pa).name() << endl;
}



