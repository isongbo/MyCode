#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vi) {
	cout << "容量：" << vi.capacity() << endl;
	cout << "大小：" << vi.size () << endl;
	cout << "内容：" << flush;
	for (vector<int>::const_iterator it =
		vi.begin (); it != vi.end (); ++it)
		cout << *it << ' ';
	cout << endl;
}
int main (void) {
	vector<int> vi;
	print (vi);
	vi.push_back (10);
	print (vi);
	vi.push_back (20);
	print (vi);
	vi.push_back (30);
	print (vi);
	vi.push_back (40);
	print (vi);
	vi.push_back (50);
	print (vi);
	vi.resize (8);
	print (vi);
	vi.resize (9);
	print (vi);
	vi.resize (5);
	print (vi);
	vi.clear (); // vi.resize (0)
	print (vi);
	vi.reserve (3);
	print (vi);
	vi.reserve (32);
	print (vi);
	vector<int> vn;
	vn.push_back (123);
	vector<int>::iterator it = vn.begin ();
	cout << *it << endl;
	vn.push_back (456);
	it = vn.begin ();
	cout << *it << endl;
	return 0;
}
