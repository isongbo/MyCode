#include <iostream>
using namespace std;
class Person{
    private:
	string  name;
	int     age;
	public:
	static int     pcount;
	public:
	Person(string name="",int age=30)
	    :name(name),age(age){  
		pcount++; 	
	}
    ~Person(){
	    pcount--;
		cout << "有人退场" << endl;
	} 
	void  show(){
		cout << "有人进场 欢迎 " << endl;
	    cout << "我是" << name << "今年" 
			<< age << "岁" << endl;
	}
};
int  Person::pcount;
void  foo(){
	cout << "现在人数:" << Person::pcount 
		<< endl;
    Person  persona("普京",58);
	persona.show();
	cout << "现在人数:" << Person::pcount 
		<< endl;
    Person  personb("奥巴马",50);
    personb.show();
	cout << "现在人数:" << Person::pcount 
		<< endl;
}
int main(){
    foo();
	cout << "现在的人数" << Person::pcount 
		 << endl;
	Person  personc("平哥",60);
    personc.show();
	cout << "现在的人数" << Person::pcount 
		 << endl;
}




