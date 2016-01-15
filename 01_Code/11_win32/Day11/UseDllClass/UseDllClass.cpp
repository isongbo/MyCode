
#include "../DllClass/DllClass.h"
#include "stdio.h"
#pragma comment( lib, "../lib/DllClass.lib" )
int main( )
{
	CMath math;
	int sum = math.Add( 5, 4 );
	int sub = math.Sub( 5, 4 );
	printf( "sum=%d,sub=%d\n", sum, sub );
	return 0;
}