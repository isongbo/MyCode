#include <iostream>
using namespace std;
class  Animal{
    public:
	string   name;
	int      age;
	public:
	void  show(){
	    cout << "this is Animal show()" 
			 << endl;
	}
};
class  Cat:public Animal{
    public:
	string  color;
	void  catfun(){
	    cout << "抓老鼠" << endl;
	}
};
/* 写一个Animal的子类 Fish  扩展一个成员变量
   string type  增加一个成员函数 fishfun */
class Fish:public Animal{
    public:
	string type;
	void   fishfun(){
	    cout << "fish fun()" << endl;
	}
};
int main(){
    cout << sizeof(Animal) << endl;
    cout << sizeof(Cat)  << endl;
	Cat  cat;
	cat.show();
	cat.catfun();
	Fish  fish;
    fish.name="test";
	fish.age=10;
    fish.type="a";
	fish.show();
	fish.fishfun();
}

