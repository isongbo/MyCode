#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
DWORD CALLBACK TestProc( LPVOID pParam )
{
	char *pszText = (char*)pParam;
	while( 1 )
	{
		printf( "%s\n", pszText );
		Sleep( 1000 );
	}
	return 0;
}
DWORD CALLBACK TestProc2( LPVOID pParam )
{
	char *pszText = (char*)pParam;
	while( 1 )
	{
		printf( "%s\n", pszText );
		Sleep( 1000 );
	}
	return 0;
}
int main(int argc, char* argv[])
{
	DWORD nID = 0;
	char *pszText = "****************************************";
	HANDLE hThread = CreateThread( NULL,
						0, TestProc, pszText, 0, &nID );
	
//	WaitForSingleObject( hThread, INFINITE );

	char *pszText2 = "----------------------------------------";
	HANDLE hThread2 = CreateThread( NULL, 0, TestProc2, pszText2, 
						0, &nID );
	getchar( );
	SuspendThread( hThread );
	ResumeThread( hThread2 );
	getchar( );
	return 0;
}
