#include <iostream>
using namespace std;
int main(){
    int  var_i=9527;
	int& ri=var_i;
	cout << &var_i << endl;
	cout << &ri << endl;
	ri=9528;
	cout << var_i << endl;
	/* 为var_i  再起一个别名 */
	int& rri=ri;
	rri=9529;
    cout << var_i  << endl;
	int  y=100;
	/* 把y的值赋值给rri  不是rri引用y  */
    rri=y;

}

