
#include "stdio.h"
_declspec(dllimport) int CPPdll_add( int add1, int add2 );
_declspec(dllimport) int CPPdll_sub( int sub1, int sub2 );
_declspec(dllimport) int CPPdll_mul( int mul1, int mul2 );
//���ϴ����c++����������
#pragma comment( lib, "../lib/CPPdll.lib" )
//֪ͨ����������ץ �����Ķ�Ӧ���

/*������Ҳ��CPPdll.lib�ļ�ץ��
����ƥ���dll�ļ���(CPPdll.dll)*/
int main( )
{
	int sum = CPPdll_add( 5, 4 );//0(CPPdll.dll)
	int sub = CPPdll_sub( 5, 4 );//1(CPPdll.dll)
	int mul = CPPdll_mul( 5, 4 );//2(CPPdll.dll)
	printf( "sum=%d,sub=%d,mul=%d\n", sum, sub, mul );
	return 0;
}