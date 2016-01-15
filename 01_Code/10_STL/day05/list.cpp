#include <iostream>
#include <list>
using namespace std;
void print (list<int> const& li) {
	for (list<int>::const_iterator it =
		li.begin (); it != li.end (); ++it)
		cout << *it << ' ';
	cout << endl;
}
bool intCmp (int x, int y) {
	return x > y;
}
int main (void) {
	list<int> l1;
	l1.push_back (10);
	l1.push_back (10);
	l1.push_back (10);
	l1.push_back (20);
	l1.push_back (20);
	l1.push_back (30);
	l1.push_back (10);
	l1.push_back (20);
	l1.push_back (30);
	l1.push_back (30);
	print (l1);
	l1.sort ();
	print (l1);
	l1.unique ();
	print (l1); // 10 20 30
	list<int> l2;
	l2.push_back (10000);
	l2.push_back (20000);
	l2.push_back (30000);
	l2.push_back (40000);
	l2.push_back (50000);
	cout << "l1：" << flush;
	print (l1);
	cout << "l2：" << flush;
	print (l2);
	list<int>::iterator pos = l1.begin ();
	++++pos; // ->30
	/*
	l1.splice (pos, l2); // O(1)
	*//*
	list<int>::iterator del = l2.begin ();
	++++del;
	l1.splice (pos, l2, del);
	*/
	list<int>::iterator begin = l2.begin ();
	++begin;
	list<int>::iterator end = l2.end ();
	--end;
	l1.splice (pos, l2, begin, end);
	cout << "l1：" << flush;
	print (l1);
	cout << "l2：" << flush;
	print (l2);
	l1.clear ();
	l2.clear ();
	l1.push_back (27);
	l1.push_back (33);
	l1.push_back (39);
	l1.push_back (48);
	l1.push_back (66);
	l1.sort (intCmp);
	l2.push_back (29);
	l2.push_back (45);
	l2.push_back (64);
	l2.sort (intCmp);
	cout << "l1：" << flush;
	print (l1);
	cout << "l2：" << flush;
	print (l2);
	l1.merge (l2, intCmp); // O(N)
	cout << "l1：" << flush;
	print (l1);
	cout << "l2：" << flush;
	print (l2);
	return 0;
}
