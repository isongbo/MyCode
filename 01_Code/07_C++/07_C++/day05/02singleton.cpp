#include <iostream>
using namespace std;
/* 饿汉式 */
class Singleton{
	 private:
     Singleton(){ cout << "Singleton()" 
		 << endl; }
	 Singleton(const Singleton& s){  }
	 static Singleton  sig;
     public:
	 static Singleton&  getInstance(){
	     return  sig;
	 }
};
Singleton   Singleton::sig;
int main(){
    Singleton& siga=Singleton::getInstance();
    Singleton& sigb=Singleton::getInstance();
	cout << &siga << ":" << &sigb << endl;
}

