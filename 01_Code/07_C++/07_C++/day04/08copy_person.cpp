#include <iostream>
using namespace std;
class Person{
    string  name;
	int     age;
	public:
	Person(string name="",int age=0)
		:name(name),age(age){
	}
	void  show(){
        cout << name << ":" << age << endl;	
	}
};
int main(){
    Person  person("刘德华",55);
    person.show();
    Person  person2=person;
	person2.show();
}

