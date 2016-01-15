#include <iostream>
using namespace std;
class  Array{
	/* 可以使用堆内存 */
    int *data;
	/* 标记数组的长度 */
	int  len;
	/* 统计数组中的元素个数 */
	int  size;
	public:
    Array(int len=5):len(len),size(0){
		cout << "Array()" << endl;
	    /* 申请堆内存 */
		data=new int[len];
	}
	~Array(){
		cout << "~Array()" << endl;
		/* 释放对应的堆内存 */
	    delete[]  data;
	}
};
void  foo(){
    Array   arr(3);
	// arr.~Array();
}
int main(){
	foo();
}

