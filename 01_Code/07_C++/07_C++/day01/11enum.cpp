#include <iostream>
using namespace std;
/* 枚举的本质就是一个小范围的整数 */
enum  Direction{D_UP,D_DOWN,D_LEFT,D_RIGHT};
int main(){
    Direction  dire=D_LEFT;
	int   x=dire;
	cout << x << endl;
	x=3;
	/* 这里体现了c++ 对类型检查的严格 */
	//dire=x;
    if(3==x){
	    dire=D_RIGHT;
	}

}

