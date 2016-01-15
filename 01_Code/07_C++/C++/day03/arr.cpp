#include <iostream>
using namespace std;
//void print (int arr[5]) {
//void print (int arr[]) {
void print (int* arr, size_t size) {
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}
void print (int (&arr)[5]) {
	for (size_t i = 0; i < sizeof (arr) /
		sizeof (arr[0]); ++i)
		cout << arr[i] << ' ';
	cout << endl;
}
int main (void) {
	int arr[5] = {1, 2, 3, 4, 5};
	print (arr, sizeof (arr) /
		sizeof (arr[0]));
	print (arr);
	return 0;
}
