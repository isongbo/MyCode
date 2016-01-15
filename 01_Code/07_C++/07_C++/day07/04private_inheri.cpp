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
class  Child:private Parent{
	public:
	void   call_parent_fun(){
	    fun_public();
		fun_protected();
		interface_private();
	}
};
int main(){
    Child   child;
	/* is  a 
    Parent  p=child; */
	// child.fun_public();
    child.call_parent_fun();
}






