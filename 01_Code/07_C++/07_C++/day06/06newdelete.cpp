#include <iostream>
#include <cstdlib>
using namespace std;
class  A{
    double  x;
	int     y;
	public:
	A(){ 
	    cout << "A()" << endl;
		x=1.0;
		y=1;
	}
	~A(){
	    cout << "~A()" << endl; 
	}
static void*  operator new(size_t size){
    cout << "size=" << size << endl;
	return  malloc(size);
}
/* 重载delete 运算符 */
static void  operator delete(void* ptr){
    cout << "ptr=" << ptr << endl;
	free(ptr);
}
};
int main(){
    A *pa=new A();
	cout << pa << endl;
	delete pa;
}



