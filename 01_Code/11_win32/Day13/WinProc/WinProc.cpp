#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
void Env( )
{
	char *pszEnv = (char*)GetEnvironmentStrings( );
	char *pszText = pszEnv;
	while( pszText[0] )
	{
		printf( "%s\n", pszText );
		pszText = pszText + strlen(pszText) + 1;
	}
	FreeEnvironmentStrings( pszEnv );
}
void Variable( )
{
	SetEnvironmentVariable( "ZJW", "GOOD" );
	char szVar[256] = { 0 };
	GetEnvironmentVariable( "ZJW", szVar, 256 );
	printf( "%s\n", szVar );
}
void ProcInfo( )
{
	DWORD nID = GetCurrentProcessId( );
	HANDLE hProc = GetCurrentProcess( );
	printf( "进程ID=%d, 进程句柄=%d\n", nID, hProc );
	getchar( );
}
void Proc( )
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	CreateProcess( "c:/windows/system32/calc.exe",
			NULL, NULL, NULL, FALSE, 0, NULL, NULL,
			&si, &pi );
	printf( "进程ID=%d,进程句柄=%d\n", pi.dwProcessId,
					pi.hProcess );
	WaitForSingleObject( pi.hProcess, INFINITE );
	printf( "计算器已死\n" );
}
void Kill( )
{
	HANDLE hProc = OpenProcess( 
			PROCESS_ALL_ACCESS, FALSE, 4056 );
	TerminateProcess( hProc, 123 );
}
int main(int argc, char* argv[])
{
//	Env( );
//	Variable( );
//	ProcInfo( );
	Proc( );
//	Kill( );
	return 0;
}
