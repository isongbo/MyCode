#include <iostream>
using namespace std;
int   x=100;
namespace  {
	/* 防止跨文件访问 */
    int  y=123;
}
int main(){
    cout << x << endl;
	cout << ::x << endl;
	cout << y << endl;
	cout << ::y << endl;
}

