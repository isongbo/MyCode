#include <iostream>
using namespace std;
class  Parent{
    public:
	void  fun_public(){
	    cout << "fun public" << endl; 
	}	
	/* 只能直接在类内 和子类中访问的数据 */
	protected:
	void  fun_protected(){
	    cout << "fun protected" << endl;
	}
	private:
	int   x;
    void  fun_private(){
	    cout << "fun private" << endl;
	}
	protected:
    void  interface_private(){
	    fun_private();
	}
};
class  Child:public Parent{
    public:
	void  call_private(){
	    interface_private();
	}
	void  call_parent_proctected(){
	    fun_protected();
	}	
    friend  void  call_parent_proctected(
		Child* c);
};
void call_parent_proctected(Child *c){
    c->fun_protected();
}
int main(){
    Child   child;
	/* is  a */
    Parent  p=child;
	child.fun_public();
	// child.fun_protected();
	child.call_parent_proctected();
	call_parent_proctected(&child);
	// child.private_fun();
	child.call_private();
}






