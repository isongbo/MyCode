#include <iostream>
using namespace std;
#define  GETMAX(X,Y)  (((X)>(Y))?(X):(Y))
inline int   getmax(int x,int y){
    return  x>y?x:y;
}
int main(){
    cout << GETMAX(100,123) << endl;
    cout << GETMAX(150,223) << endl;
}

