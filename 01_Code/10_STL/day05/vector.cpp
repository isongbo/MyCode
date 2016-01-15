#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vi) {
	cout << "字节数：" << sizeof (vi) << endl;
	size_t size = vi.size ();
	cout << "元素数：" << size << endl;
	cout << "元素值：" << flush;
	/*
	for (size_t i = 0; i < size; ++i)
		cout << vi[i] << ' ';
	*/
	for (vector<int>::const_iterator it
		= vi.begin (); it != vi.end (); ++it)
		cout << /*++*/*it << ' ';
	cout << endl;
}
void rprint (vector<int> const& vi) {
	for (vector<int>::const_reverse_iterator
		it = vi.rbegin (); it != vi.rend ();
		++it)
		cout << *it << ' ';
	cout << endl;
}
template<typename T>
T add (T const& x, T const& y) {
	size_t size = x.size ();
	T z (size);
	for (size_t i = 0; i < size; ++i)
		z[i] = x[i] + y[i];
	return z;
}
int main (void) {
	vector<int> v1;
	print (v1);
	vector<int> v2 (3);
	print (v2);
	vector<int> v3 (3, 7);
	print (v3);
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int> v4 (a+2, a+5);
	print (v4);
	v1 = v4;
	print (v1);
	v1 = add (v3, v4);
	print (v1);
	vector<int> v5;
	v5.push_back (10);
	v5.push_back (30);
	v5.push_back (50);
	print (v5);
//	v5.push_front (0);
	v5.pop_back ();
	print (v5);
	v5.front ()++;
	v5.back () -= 10;
	print (v5); // 11 20
	vector<int>::iterator it;
	for (it = v5.begin (); it != v5.end ();
		++it)
		*it *= *it;
	print (v5); // 121 400
	rprint (v5);
	it = v5.begin ();
	++it;
	v5.insert (it, 300);
	print (v5); // 121 300 400
	it = v5.begin ();
	it += 2;
	v5.insert (it, 350);
	print (v5); // 121 300 350 400 <END>
	v5.insert ( // O(N)
		v5.insert (v5.end () - 3, 200), 150);
	print (v5); // 121 150 200 300 350 400 <E>
	cout << boolalpha;
	cout << (v5.end () > v5.begin ()) << endl;
	cout << (v5.rend ()> v5.rbegin()) << endl;
	cout << v5.end () - v5.begin () << endl;
	cout << v5.rend () - v5.rbegin () << endl;
//	cout << v5.end () + v5.begin () << endl;
	it = v5.begin () + 2; // ->200
	v5.erase (v5.erase (it)); // O(N)
	print (v5);
	return 0;
}
