
#include "stdio.h"
int CPPlib_add( int add1, int add2 );
int CPPlib_sub( int sub1, int sub2 );
//���������������������ġ�
#pragma comment( lib, "../lib/CPPlib.lib" )
//֪ͨ �������� ��ץԴ����
extern "C"int Clib_add( int add1, int add2 );
extern "C"int Clib_sub( int sub1, int sub2 );
#pragma comment( lib, "../lib/Clib.lib" )
int main( )
{
	int sum = CPPlib_add( 5, 4 );
	int sub = CPPlib_sub( 5, 4 );
	printf( "sum=%d,sub=%d\n", sum, sub );
	sum = Clib_add( 5, 3 );
	sub = Clib_sub( 5, 3 );
	printf( "sum=%d,sub=%d\n", sum, sub );
	return 0;
}