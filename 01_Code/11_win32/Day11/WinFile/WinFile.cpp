// WinFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
void Create( )
{
	HANDLE hFile=CreateFile( "c:/file.txt", GENERIC_WRITE,
				FILE_SHARE_READ, NULL, CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL, NULL );
	CloseHandle( hFile );
}
void Write( )
{
	HANDLE hFile=CreateFile( "c:/file.txt", GENERIC_WRITE,
				FILE_SHARE_READ, NULL, OPEN_ALWAYS, 
				FILE_ATTRIBUTE_NORMAL, NULL );
	char szText[] = "hello file";
	DWORD nLen = 0;
	WriteFile(hFile, szText, strlen(szText), &nLen, NULL);
	printf( "准备写入:%d,实际写入:%d\n", 
				strlen(szText), nLen );
	CloseHandle( hFile );
}
void Read( )
{
	HANDLE hFile=CreateFile( "c:/file.txt", GENERIC_READ,
					FILE_SHARE_READ, NULL, OPEN_ALWAYS,
					FILE_ATTRIBUTE_NORMAL, NULL );
	DWORD nHight = 0;
	DWORD nLow = GetFileSize( hFile, &nHight );
	char szText[256] = { 0 };
	DWORD nLen = 0;
	ReadFile( hFile, szText, nLow, &nLen, NULL );
	printf( "数据:%s,准备读取:%d,实际读取:%d\n",
			szText, nLow, nLen );
	CloseHandle( hFile );
}
void UseFile( )
{
//	CopyFile( "c:/file.txt", "c:/123/nofile.txt", FALSE );
//	DeleteFile( "c:/file.txt" );
	MoveFile( "c:/123/nofile.txt", "c:/file.txt" );
}
void Find( )
{
	char *szPath = "c:/*.*";
	WIN32_FIND_DATA wfd = { 0 };
	HANDLE hFind = FindFirstFile( szPath, &wfd );
	BOOL goFind = TRUE;
	while( goFind )
	{
		if(wfd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
		{
			printf( "[%s]\n", wfd.cFileName );
		}else{
			printf( "%s\n", wfd.cFileName );
		}
		goFind = FindNextFile( hFind, &wfd );
	}
	FindClose( hFind );
}
int main(int argc, char* argv[])
{
//	Create( );
//	Write( );
//	Read( );
//	UseFile( );
	Find( );
	return 0;
}
