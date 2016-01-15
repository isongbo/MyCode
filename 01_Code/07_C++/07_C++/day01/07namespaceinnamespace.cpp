#include <iostream>
using namespace std;
namespace  ns1{
    int   age=1;
	namespace ns2{
	    int  age=21;
		void  show(){
		    cout << "ns2 age is " << age 
				 << endl;
			cout << "ns1 age is " << ns1::age
				 << endl;
		}
        namespace ns3{
		    void  show(){
			    cout << "this is ns3" << endl;
			}
		} 
	}
}
/* 命名空间重命名 */
namespace ns4=ns1::ns2::ns3;
int main(){
    ns1::ns2::show();
	ns1::ns2::ns3::show();
	ns4::show();
}



