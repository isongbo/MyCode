#include <iostream>
using namespace std;
class A {};
class B : public A {};
int main (void) {
	try {
		throw A ();
//		throw B ();
	}
	catch (B& ex) {
		cout << "异常B" << endl;
	}
	catch (A& ex) {
		cout << "异常A" << endl;
	}
	/*
	catch (B& ex) {
		cout << "异常B" << endl;
	}
	*/
	return 0;
}
