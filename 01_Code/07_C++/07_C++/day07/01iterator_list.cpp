#include <list>
#include <iostream>
using namespace std;
int main(){
    list<int>  datas;
	datas.push_back(9);
	datas.push_back(5);
	datas.push_back(2);
	datas.push_back(7);
	/* 这是内部类 类型 */
	list<int>::iterator  it;
	/* 得到指向第一个元素的迭代器 */
	it=datas.begin();
    cout << *it << endl;
    it++;
	cout << *it << endl;
    it++;
	cout << *it << endl;
    it++;
	cout << *it << endl;
    /* 使用循环 遍历链表 */
	it=datas.begin();
	/* end() 是获取最后一个元素后面对应的
	   迭代器 */
	while(it!=datas.end()){
	    cout << *it++ << ' ';
	}
	cout << endl;
}





