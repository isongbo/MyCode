

#pragma comment( lib, "../lib/Cdll.lib" )

int main( )
{
	int sum, sub;
	sum = Cdll_add( 5, 6 );
	sub = Cdll_sub( 5, 6 );
	printf( "sum=%d,sub=%d\n", sum, sub );
	return 0;
}