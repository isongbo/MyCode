#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
void HeapInfo( )
{
	HANDLE hHeap = GetProcessHeap( );
	printf( "第一个堆:%d\n", hHeap );
	HANDLE hHeaps[256] = { 0 };
	DWORD nCount = GetProcessHeaps( 256, hHeaps );
	for( DWORD i=0; i<nCount; i++ )
	{
		printf( "%d-%d\n", i, hHeaps[i] );
	}
}
void Heap( )
{
	HANDLE hHeap = HeapCreate( 
				HEAP_NO_SERIALIZE, 1024*1024, 0 );
	//内核中创建一个堆结构同时申请1M内存,堆结构维护1M内存
	char *pszText = (char *)HeapAlloc( hHeap, 
					HEAP_ZERO_MEMORY, 2*1024*1024 );
	//将hHeap找到的堆结构维护内存和本进程地址建立映射关系
	strcpy( pszText, "hello heap" );
	printf( "%s\n", pszText );
	HeapFree( hHeap, 0, pszText );
	//将 hHeap找到的堆结构维护内存和本进程地址解除映射
	HeapDestroy( hHeap );
	//将内核中的堆结构销毁，堆结构维护的内存“彻底”释放
}
int main(int argc, char* argv[])
{
//	HeapInfo( );
	Heap( );
	return 0;
}
