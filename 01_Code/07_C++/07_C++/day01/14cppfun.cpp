#include <iostream>
using namespace std;
void   show(){
    cout << "this is show()" << endl;
}
int  getmax(int x,int y);
int  getmin(int x,int y){
    return x>y?y:x;
}
int main(){
    show();
	//show(1);
	// show(1,2);
	cout << getmax(100,123) << endl;
	cout << getmin(100,123) << endl;
}
int   getmax(int x,int y){
    return x>y?x:y;
}

