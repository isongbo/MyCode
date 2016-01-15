
#include "windows.h"
#include "stdio.h"
typedef int(*DLL_ADD)(int m, int n);
typedef int(*DLL_SUB)(int m, int n);
typedef int(*DLL_MUL)(int m, int n);
int main( )
{
	HINSTANCE hDll = LoadLibrary( "CPPdll.dll" );
	printf( "hDll:%d\n", hDll );

	DLL_ADD myAdd = (DLL_ADD)GetProcAddress(
						hDll, "CPPdll_add" );
	printf( "myAdd:%p\n", myAdd );
	int sum = myAdd( 5, 4 );
	printf( "sum=%d\n", sum );

	DLL_SUB mySub = (DLL_SUB)GetProcAddress( 
						hDll, "CPPdll_sub" );
	printf( "mySub:%p\n", mySub );
	int sub = mySub( 5, 4 );
	printf( "sub=%d\n", sub );

	DLL_MUL myMul = (DLL_MUL)GetProcAddress(
						hDll, "?CPPdll_mul@@YAHHH@Z" );
	printf( "myMul:%p\n", myMul );
	int mul = myMul( 5, 4 );
	printf( "mul=%d\n", mul );

	FreeLibrary( hDll );
	return 0;
}