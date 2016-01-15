#include <iostream>
#include <cstring>
using namespace std;
string strmax (string x, string y) {
	return x > y ? x : y;
}
int main (void) {
	// 直接使用字面值
	cout << "Hello, World !" << endl;
	// 通过字符指针
	char const* p = "Hello, World !";
	cout << p << endl;
	// 通过字符数组
	char a[] = "Hello, World !";
	cout << a << endl;
	// 通过字符串对象
	string s = "Hello, World !";
	cout << s << endl;
	// 复制
	string s2 = s;
	cout << s2 << endl;
	s2[0] = 'h'; // 通过下标访问单个字符
	s2[7] = 'w';
	cout << s2 << endl;
	cout << s << endl;
	// 拼接
	s2 += "达内科技";
	cout << s2 << endl;
	// 比较
	cout << strmax ("hello", "world") << endl;
	cout << strmax ("abc", "abcd") << endl;
	// 交换
	string x ("ABCD"), y ("1234");
	x.swap (y);
	cout << x << ' ' << y << endl;
	// 长度
	cout << x.length () << endl;
	cout << strlen (x.c_str ()) << endl;
	// 子串
	string z = "1234ABC5678";
	string b = z.substr (4, 3);
	cout << b << endl;
	b = z.substr (4);
	cout << b << endl;
	// 查找/替换
	z.replace (z.find ("ABC", 0), 3, "HELLO");
	cout << z << endl;
	// 插入
	z.insert (9, "WORLD");
	cout << z << endl;
	// 删除
	z.erase (9, 5);
	cout << z << endl;
	// 1234HELLO5678
	//       ^
	size_t pos = z.find_first_of ("ADLO", 0);
	cout << pos << endl;
	// 不能通过sizeof求字符串长度
	cout << sizeof (z) << endl;
	return 0;
}
