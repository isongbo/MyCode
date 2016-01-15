#include <iostream>
#include <memory>
using namespace std;
class  A{
    public:
	A(){ cout << "A()" << endl;  }	
	~A(){ cout << "~A()" << endl; }
	void  ashow(){
	    cout << "this is A show()" << endl;
	}
};
class myauto_ptr{
    A  *pa;
	public:
	myauto_ptr(A* pa=NULL):pa(pa){  }
	void  ashow(){ 
		cout << "this ptr show()" << endl;
	}
	~myauto_ptr(){
	    delete  pa;
	}
	/* 指针运算符 -> 重载 */
    A*   operator->(){
	    // return  pa;
		return  &**this;
	} 
	/* 重载*号运算符  */
    A&  operator*(){
	    return *pa;
	}
};
void  foo(){
    A *pa=new A();
	// auto_ptr<A> myptr(pa);
	myauto_ptr   myptr(pa);
    pa->ashow();
	// myptr->ashow();
	myptr.ashow();
	myptr->ashow();
	myptr.operator->()->ashow();
	(*myptr).ashow();
}
int main(){
    foo();
}

