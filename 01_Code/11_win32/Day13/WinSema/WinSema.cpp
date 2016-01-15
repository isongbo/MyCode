#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
HANDLE g_hSema = 0;//接收信号量句柄（可等候句柄）
DWORD CALLBACK TestProc( LPVOID pParam )
{
	while( 1 )
	{
		WaitForSingleObject( g_hSema, INFINITE );
		printf( "*********************\n" );
	}
	return 0;
}

int main(int argc, char* argv[])
{
	g_hSema = CreateSemaphore( NULL, 3, 10, NULL );
	DWORD nID = 0;
	HANDLE hThread = CreateThread( NULL, 0, TestProc,
						NULL, 0, &nID );
	getchar( );
	ReleaseSemaphore( g_hSema, 10, NULL );
	WaitForSingleObject( hThread, INFINITE );
	CloseHandle( hThread );
	CloseHandle( g_hSema );
	return 0;
}
