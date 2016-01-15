#include <iostream>
using namespace std;
class Integer{
	private:
    int  data;
	public:
	Integer(int data=0):data(data){
	}
	/* operator-  单参构造原则 */
	Integer  operator-(const Integer& i){
	    return  data-i.data;
	}
	/* 写一个一元运算符 完成前加加 ++ia */
    Integer&  operator++(){
	    data++;
		return *this;
	}
	/* 写一个后加加 */
    Integer   operator++(int){
	    return  data++;
	}
	/* 写一个一元的负号运算符 */
	Integer   operator-(){
	    return  -data; 
	}
	/* 一元运算符 operator~  */
	Integer  operator~(){
	    return  Integer(~data); 
	}
	Integer  operator!(){
	    return  !data;
	}
	friend ostream& operator <<(ostream& os,
		const Integer& i);
	friend istream& operator>>(istream& is,
		Integer& i);
};
ostream& operator<<(ostream& os,
	const Integer& i){
    return  os << i.data;
}
istream& operator>>(istream& is,Integer& i){
	cout << "请输入一个整数:" << endl;
    return  cin >> i.data;
}
int main(){
    Integer  ia(1);
	// cout << ++++ia << endl;
	cout << ia++ << endl;
	cout << ia << endl;
	Integer  ib(9);
    cout << ~ia << endl;
	cout << ~ib << endl;
	cout << !ia << endl;
	cout << !!ib << endl;
	cout << -ib  << endl;
	cout << -(-ib)  << endl;
    
}

