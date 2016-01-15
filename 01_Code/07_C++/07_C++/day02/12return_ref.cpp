#include <iostream>
using namespace std;
/* int  getmax(int x,int y){
    return  x>y?x:y;
}*/
int&  getmax(int& x,int& y){
    return  x>y?x:y;
}
int&  getInt(){
    static int  x=123;
    return x; 
}
int main(){
    // int res=getmax(1,2);
	int  x=1;
	int  y=2;
	getmax(x,y)=100;
	cout << y << endl;
	cout << getInt() << endl;
}



