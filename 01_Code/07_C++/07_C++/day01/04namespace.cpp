#include <iostream>
using namespace std;
namespace  IBM{
    int   age=50;
	double salary;
	void  show(){
	    cout << "this is IBM age is " << 
			age << endl;
	}
}

namespace  tarena{
    int   age;
	void  show(){
	    cout << "this is tarena age is " 
			<< age << endl;
	}
	void  showtarena();
}

namespace  tarena{
    void  showtarena(){
	    cout << "纳斯达克上市公司" << endl;
	}
}
int main(){
	tarena::showtarena();
	tarena::age=13;
	tarena::show();
	IBM::salary=8000;
    cout << IBM::salary << endl;
	IBM::show();
}


