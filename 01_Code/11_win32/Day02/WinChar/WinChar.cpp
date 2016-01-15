#include "stdafx.h"
#include "stdio.h"
#define UNICODE
#include "windows.h"
#define WIDECHAR

void T_char( )
{
	TCHAR *pszText = __TEXT("hello");
#ifdef UNICODE
	wprintf( L"%s\n", pszText );
#else
	printf( "单:%s\n", pszText );
#endif
/*
#ifdef WIDECHAR
	wchar_t *pszText = L"hello";
	wprintf( L"%s\n", pszText );
#else
	char *pszText = "hello";
	printf( "单：%s\n", pszText );
#endif*/
}


void C_char( )
{
	char *pszText = "hello char";
	printf( "%s\n", pszText );
}
void W_char( )
{
	wchar_t *pwszText = L"hello wchar";
	int nLen = wcslen(pwszText);
	wprintf( L"%s %d\n", pwszText, nLen );
}
void PrintUnicode( )
{
	HANDLE hStd = GetStdHandle( STD_OUTPUT_HANDLE );
	//获取标准输出句柄
	for( WORD nHigh=100; nHigh<200; nHigh++ )
	{
		for ( WORD nLow=100; nLow<200; nLow++ )
		{
			wchar_t wChar = nHigh*256 + nLow;
//			wprintf( L"%s", &wChar );
			WriteConsole( hStd, &wChar, 1, NULL, NULL );
		}
		printf( "\n" );
	}
}
int main(int argc, char* argv[])
{
//	C_char( );
//	W_char( );
//	T_char( );
	PrintUnicode( );
	return 0;
}
