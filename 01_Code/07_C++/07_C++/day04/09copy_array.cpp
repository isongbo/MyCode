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
	/* 拷贝构造函数 完成深拷贝 */
	Array(const Array& arr){
	    cout << "Array(const Array())" 
			 << endl;
		len=arr.len;
		size=arr.size;
		/* 重新申请堆内存 */
		data=new int[len];
		/* 复制堆内存中的数据 */
        for(int  i=0;i<size;i++){
		    data[i]=arr.data[i];   
		} 
	}
	/* 提供一个显示数组数据的函数 */
    void  show(){
	    for(int i=0;i<size;i++){
		    cout << data[i] << ' ';
		}
		cout << endl;
	}
	/* 提供一个增加数据的函数  堆内存不够
	   就扩容 堆空间扩大为原来的1倍加1 */
    void  push_back(int  d){
	    if(size==len){
		    // 扩容
			expend();
		}
        data[size++]=d;
	}
	void  expend(){
	    len=len*2+1;
		/* 保留原来堆的地址 */
		int* temp=data;
		/* 重新申请堆内存 */
		data=new int[len];
		/* 复制原来的数据 */
        for(int i=0;i<size;i++){
		    data[i]=temp[i];
		}
		/* 释放原来的内存 */
		delete[]  temp;
	}
};
void  foo(){
    Array   arra(3);
	arra.push_back(9);
	arra.push_back(5);
	arra.push_back(2);
	arra.push_back(7);
	arra.push_back(8);
	Array   arrb=arra;
	// arr.~Array();
	arrb.show();
}
int main(){
	foo();
}

