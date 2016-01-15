#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
void status( )
{
	MEMORYSTATUS ms = { 0 };
	ms.dwLength = sizeof( ms );
	GlobalMemoryStatus( &ms );
	printf( "Load:%d\n", ms.dwMemoryLoad );
	printf( "TotalPhys:%u\n", ms.dwTotalPhys );
	printf( "AvliaPhys:%u\n", ms.dwAvailPhys );
	printf( "TotalVirt:%u\n", ms.dwTotalPageFile );
	printf( "AvliaVirt:%u\n", ms.dwAvailPageFile );

	printf( "TotalAddr:%u\n", ms.dwTotalVirtual );
	printf( "AvliaAddr:%u\n", ms.dwAvailVirtual );
	printf( "******************************\n" );
}
void Virtual_Info( )
{
	status( );
	char *pszText = (char*)VirtualAlloc( NULL, 
				1024*1024*1024, 
				MEM_COMMIT, PAGE_READWRITE );
	/*
	MEM_COMMIT - 连 地址 带 内存 都要
	MEM_RESERVE - 只要 地址 不要 内存
	*/
	status( );
	VirtualFree( pszText, 0, MEM_RELEASE );
	status( );
	/*
	MEM_DECOMMIT - 只释放 内存 不释放 地址
	MEM_RELEASE - 连 地址 带 内存 都释放
	*/
}
void Virtual_Commit( )
{
	char *pszText = (char*)VirtualAlloc( NULL, 
					4096, MEM_COMMIT, PAGE_READWRITE);
	strcpy( pszText, "hello commit" );
	printf( "%s\n", pszText );
	VirtualFree( pszText, 0, MEM_RELEASE );
}
void Virtual_Reserve( )
{
	char *pszText = (char*)VirtualAlloc( NULL, 
				1024*1024*1024, 
				MEM_RESERVE, PAGE_READWRITE );
	char *pszText1 = (char*)VirtualAlloc( pszText+4096, 
				1, MEM_COMMIT, PAGE_READWRITE );

	strcpy( pszText1, "hello reserve" );
	printf( "%s\n", pszText1 );
	VirtualFree( pszText, 0, MEM_RELEASE );
}
int main(int argc, char* argv[])
{
//	Virtual_Info( );
//	Virtual_Commit( );
	Virtual_Reserve( );
	return 0;
}
