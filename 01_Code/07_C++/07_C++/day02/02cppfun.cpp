#include <iostream>
using namespace std;
/* _Z6getmaxii */
int  getmax(int x,int y){
    return  x>y?x:y;
}
/* _Z6getmaxid  */
double getmax(int x,double y){
    return  x>y?x:y;
}
int main(){
    getmax(1,2);
	getmax(1,2.5);
}

