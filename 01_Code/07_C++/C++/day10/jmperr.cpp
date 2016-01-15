#include <csetjmp>
#include <cstdio>
#include <iostream>
using namespace std;
jmp_buf g_env;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
};
void fun3 (void) {
	A a;
	FILE* fp = fopen ("none", "r");
	if (! fp)
		longjmp (g_env, -1);
	// ...
}
void fun2 (void) {
	A a;
	// ...
	fun3 ();
	// ...
}
void fun1 (void) {
	A a;
	// ...
	fun2 ();
	// ...
}
int main (void) {
	int ret = setjmp (g_env);
	if (ret == -1) {
		cout << "文件打开失败！" << endl;
		return -1;
	}
	fun1 ();
	// ...
	cout << "成功！" << endl;
	return 0;
}
