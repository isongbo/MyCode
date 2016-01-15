#include <iostream>
using namespace std;
class A{
	double  x;
    public:
	A(){
	    cout << "A()" << endl;
	}	
	A(const A& a){
	    cout << "A(constA&)" << endl;
	}
};
void  printA(const A& a){

}
A&  getA(A&  a){
   return  a; 
}
/* 特殊情况  */
A   getA2(){
   /* A  a;
   return  a; */
   /* 使用匿名对象 简化编程 */
   return  A();
}
int main(){
   /* const A   a;
    A   b=a;
	printA(b);
    getA(b); */
    A  c= getA2();
}



