#include <iostream>
#include <stdexcept>
using namespace std;
class OverFlow : public exception {
private:
	char const* what (void) const throw () {
		return "我的堆栈上溢了啊！";
	}
};
void push (int data) {
	// ...
//	throw overflow_error ("堆栈上溢！");
	throw OverFlow ();
}
int main (void) {
	try {
		push (100);
	}
	/*
	catch (overflow_error& ex) { ... }
	catch (OverFlow& ex) { ... }
	catch (bad_alloc& ex) { ... }
	*/
	catch (exception& ex) {
		cout << ex.what () << endl;
		return -1;
	}
	return 0;
}
