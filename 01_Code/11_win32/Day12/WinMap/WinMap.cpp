#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
//	HANDLE hFile = CreateFile( "c:/map.dat", 
//		GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ,
//		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE hMap = CreateFileMapping( NULL, NULL, 
			PAGE_READWRITE, 0, 1024*1024, "ZJW" );
	//如果第一个参数为 hFile 内核中创建一个结构
	//（内存映射文件）维护一个硬盘文件

	//如果第一个参数为 NULL 内核中创建一个结构
	//（内存映射文件）,同时申请1M内存，内存映射文件维护
	//1M内存
	char *pszText = (char*)MapViewOfFile( 
			hMap, FILE_MAP_ALL_ACCESS, 0, 64*1024, 0 );
	//将hMap找到的内核结构维护的硬盘文件和本进程地址建立映射
	//将hMap找到的内核结构维护的1M内存和本进程地址建立映射
	strcpy( pszText, "hello map" );
//	printf( "%s\n", pszText );
	UnmapViewOfFile( pszText );
	//将本进程地址 和 硬盘文件 解除映射
	//将本进程地址 和 1M内存 解除映射
	CloseHandle( hMap );
	//内存映射文件这个结构 一旦关闭就没了
//	CloseHandle( hFile );
	return 0;
}
