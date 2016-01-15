#include <iostream>
using namespace std;
ostream& red (ostream& os) {
	return os << "\033[;;31m";
}
ostream& green (ostream& os) {
	return os << "\033[;;32m";
}
ostream& def (ostream& os) {
	return os << "\033[0m";
}
int main (void) {
	cout << red << "Hello, " << green
		<< "World !" << def << endl;
	return 0;
}
