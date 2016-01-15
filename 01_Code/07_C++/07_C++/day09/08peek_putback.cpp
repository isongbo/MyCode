#include <iostream>
using namespace std;
int main(){
    int  c;
	/* c=cin.get();
	cin.putback(c); */
	c=cin.peek();
	if(c>='0' && c <='9'){
	     int  x;
		 cin >> x;
		 cout << "x=" << x << endl;
	}else{
	     string  name;
		 cin >> name;
		 cout << "name=" << name << endl;
	}
}

