#include <iostream>
using namespace std;
int  getmax(int x,int y,int z){

}
int  getmax(int x,int y=1);
int main(){
    cout << getmax(100) << endl;
	cout << getmax(0) << endl;
	cout << getmax(2,10) << endl;
}
int  getmax(int x,int y){
    return  x>y?x:y;
}

