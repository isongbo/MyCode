#include <iostream>
using namespace std;
enum Color {RED, GREEN, BLUE};
int main (void) {
//	Color color = 100;
//	Color color = 0;
	Color color = RED;
	color = GREEN;
//	color = 2;
	color = BLUE;
	cout << color << endl;
	int i = color;
	cout << i << endl;
	return 0;
}
