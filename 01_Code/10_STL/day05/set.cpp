#include <iostream>
#include <set>
using namespace std;
int main (void) {
	set<int> si;
	si.insert (13);
	si.insert (17);
	si.insert (13);
	si.insert (25);
	si.insert (17);
	for (set<int>::iterator it = si.begin ();
		it != si.end (); ++it)
		cout << *it << endl;
	cout << "--------" << endl;
	multiset<int> ms;
	ms.insert (13);
	ms.insert (17);
	ms.insert (13);
	ms.insert (25);
	ms.insert (17);
	for (multiset<int>::iterator it =
		ms.begin (); it != ms.end (); ++it)
		cout << *it << endl;
	return 0;
}
