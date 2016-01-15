#include <iostream>
#include <map>
using namespace std;
int main (void) {
	multimap<string, int> si;
	si.insert (make_pair ("张飞", 10000));
	si.insert (make_pair ("赵云", 20000));
	si.insert (make_pair ("张飞", 30000));
	si.insert (make_pair ("关羽", 40000));
	si.insert (make_pair ("赵云", 50000));
	si.insert (make_pair ("关羽", 60000));
	typedef multimap<string,int>::iterator IT;
	for (IT it = si.begin (); it != si.end ();
		++it)
		cout << it->first << "：" <<
			it->second << endl;
	cout << "-----------" << endl;
	IT lower = si.lower_bound ("张飞");
	IT upper = si.upper_bound ("张飞");
	for (IT it = lower; it != upper; ++it)
		cout << it->first << "：" <<
			it->second << endl;
	cout << "-----------" << endl;
	pair<IT, IT> res = si.equal_range("赵云");
	for (IT it = res.first; it != res.second;
		++it)
		cout << it->first << "：" <<
			it->second << endl;
	return 0;
}
