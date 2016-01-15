#include <iostream>
using namespace std;
class Integer{
    private:
	int   data;
	public:
	Integer(int data=0):data(data){
	
	}
	friend ostream& operator<<(ostream& os,
		const Integer& i);
	friend istream& operator>>(istream& is,
		Integer&  i);
	friend Integer&  operator++(Integer& i);
	friend const Integer operator++(Integer& i,int);
	/* 提供一个判断相等的运算符 == */
    bool  operator==(const Integer& i){
	    // return  this==&i;
		return  data==i.data;
	}
};
/* 输入输出运算符的重载 */
ostream& operator<<(ostream& os,
	const Integer& i){
    return  os << i.data;
}
istream& operator>>(istream& is,
	Integer&  i){
	cout << "请输入一个整数:" << endl;
    return  is >> i.data;
}
/* 写一个全局形式形式的前加加 */
Integer&   operator++(Integer& i){
    i.data++;
	return i;
}
/* 写一个全局形式的后加加 */
const Integer  operator++(Integer& i,int){
    return  i.data++;
}
int main(){
	Integer  var_i=102;
    Integer  i(101);
	// cout << ++i << endl;
	// cout << (i++)++ << endl;
	/* 类类型的临时结果要想 不被覆盖掉 需要
	   自己加const保护 */
	// (i++)=100;
	cout << i << endl;
	Integer  i2(105);
	cin >> i;
	cout << i << endl;
    cout << (i==i2) << endl;
}

