#include <iostream>
#include <map>
using namespace std;
int main (void) {
	map<string, int> si;
	si.insert (pair<string, int> ("张飞",90));
	si.insert (make_pair ("赵云", 85));
	si["关羽"] = 95;
	pair<map<string, int>::iterator, 
		bool> res = si.insert (make_pair (
		/*"关羽"*/"黄忠", 50));
	if (! res.second)
		cout << "插入失败！" << endl;
	else
		cout << "插入成功：" <<
			res.first->first << " - " <<
			res.first->second << endl;
	si.erase ("赵云");
	for (map<string, int>::iterator it =
		si.begin (); it != si.end (); ++it)
		cout << it->first << "："
			<< it->second << endl;
	cout << si["赵云"] << endl;
	si["张飞"] = 0;
	cout << si["张飞"] << endl;
	map<string, int>::iterator it =
		si.find ("赵");
	if (it != si.end ())
		cout << it->second << endl;
	else
		cout << "查无此人！" << endl;
	return 0;
}
