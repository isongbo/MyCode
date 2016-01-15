
#include "stdio.h"
_declspec(dllimport) int CPPdll_add( int add1, int add2 );
_declspec(dllimport) int CPPdll_sub( int sub1, int sub2 );
_declspec(dllimport) int CPPdll_mul( int mul1, int mul2 );
//以上代码给c++编译器看的
#pragma comment( lib, "../lib/CPPdll.lib" )
//通知链接器到哪抓 函数的对应编号

/*链接器也从CPPdll.lib文件抓了
和它匹配的dll文件名(CPPdll.dll)*/
int main( )
{
	int sum = CPPdll_add( 5, 4 );//0(CPPdll.dll)
	int sub = CPPdll_sub( 5, 4 );//1(CPPdll.dll)
	int mul = CPPdll_mul( 5, 4 );//2(CPPdll.dll)
	printf( "sum=%d,sub=%d,mul=%d\n", sum, sub, mul );
	return 0;
}