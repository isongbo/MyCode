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
	//�����һ������Ϊ hFile �ں��д���һ���ṹ
	//���ڴ�ӳ���ļ���ά��һ��Ӳ���ļ�

	//�����һ������Ϊ NULL �ں��д���һ���ṹ
	//���ڴ�ӳ���ļ���,ͬʱ����1M�ڴ棬�ڴ�ӳ���ļ�ά��
	//1M�ڴ�
	char *pszText = (char*)MapViewOfFile( 
			hMap, FILE_MAP_ALL_ACCESS, 0, 64*1024, 0 );
	//��hMap�ҵ����ں˽ṹά����Ӳ���ļ��ͱ����̵�ַ����ӳ��
	//��hMap�ҵ����ں˽ṹά����1M�ڴ�ͱ����̵�ַ����ӳ��
	strcpy( pszText, "hello map" );
//	printf( "%s\n", pszText );
	UnmapViewOfFile( pszText );
	//�������̵�ַ �� Ӳ���ļ� ���ӳ��
	//�������̵�ַ �� 1M�ڴ� ���ӳ��
	CloseHandle( hMap );
	//�ڴ�ӳ���ļ�����ṹ һ���رվ�û��
//	CloseHandle( hFile );
	return 0;
}
