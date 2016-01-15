#include <iostream>
using namespace std;
class Integer{
	private:
    int  data;
	public:
	Integer(int data=0):data(data){
	}
	/* operator+ */
	Integer  operator+(const Integer& i){
	    return  Integer(data+i.data); 
	}
	/* operator-  单参构造原则 */
	Integer  operator-(const Integer& i){
	    return  data-i.data;
	}
	/* operator* */
    Integer  operator*(const Integer& i){
	    return  data*i.data;
	}
	Integer  operator/(const Integer& i){
	    return  data/i.data; 
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
	Integer  ib(9);
	cin >> ia;
    Integer  ic=ia/ib;
	cout << ic << endl;
}

