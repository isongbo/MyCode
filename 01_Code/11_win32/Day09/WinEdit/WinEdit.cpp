#include "stdafx.h"
#include "resource.h"
#include "stdio.h"
#include "stdlib.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnCreate( HWND hWnd )
{
	HWND hEdit = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "hello", 
			WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|
			ES_MULTILINE|ES_AUTOVSCROLL|WS_HSCROLL|
			WS_VSCROLL,
			0, 0, 200, 200, hWnd, (HMENU)1001,
			g_hInstance, NULL );
	//ES_PASSWORD - �������ڵ��б༭��
	//ES_NUMBER - ����ֻ���������ּ������������ַ���
	HFONT hFont = CreateFont( 30, 0, 0, 0, 900, 0, 0, 0,
					GB2312_CHARSET, 0, 0, 0, 0, "����" );
	SendMessage( hEdit, WM_SETFONT, (WPARAM)hFont, 1 );
}
void OnSize( HWND hWnd, LPARAM lParam )
{
	int nWidth = LOWORD(lParam);
	int nHight = HIWORD(lParam);
	HWND hEdit = GetDlgItem( hWnd, 1001 );
	MoveWindow( hEdit, 0, 0, nWidth, nHight, TRUE );
}
void OnSave( HWND hWnd )
{
	HWND hEdit = GetDlgItem( hWnd, 1001 );
	LRESULT nLen = SendMessage( 
					hEdit, WM_GETTEXTLENGTH, 0, 0 );
	char *pszText = (char*)malloc( nLen+1 );
	memset( pszText, 0, nLen+1 );
	SendMessage(hEdit,WM_GETTEXT,nLen+1,(LPARAM)pszText);
	FILE *pFile = fopen( "c:/my.txt", "w" );
	fwrite( pszText, 1, nLen, pFile );
	fclose( pFile );
	free( pszText );
}
void OnOpen( HWND hWnd )
{
	FILE *pFile = fopen( "c:/my.txt", "r" );
	fseek( pFile, 0, SEEK_END );
	long nLen = ftell( pFile );
	char *pszText = (char*)malloc( nLen+1 );
	memset( pszText, 0, nLen+1 );
	fseek( pFile, 0, SEEK_SET );
	fread( pszText, 1, nLen, pFile );
	fclose( pFile );
	HWND hEdit = GetDlgItem( hWnd, 1001 );
	SendMessage( hEdit, WM_SETTEXT, 0, (LPARAM)pszText );
	free( pszText );
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_SAVE:
		OnSave( hWnd );//����
		break;
	case ID_OPEN:
		OnOpen( hWnd );//��
		break;
	}
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_CTLCOLOREDIT:
		{
			HDC hdcEdit = (HDC)wParam;
			SetTextColor( hdcEdit, RGB(0,255,0) );
			SetBkColor( hdcEdit, RGB(255,0,0) );
			return (LRESULT)CreateSolidBrush( RGB(255,0,0) );
		}
		break;
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_SIZE:
		OnSize( hWnd, lParam );
		break;
	case WM_CREATE:
		OnCreate( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );//����ʹGetMessage����0����
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam );
			//��������Ϣ��Ĭ�ϴ���
}
//ע�ᴰ����
void Register( LPSTR lpClassName, WNDPROC wndproc )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;//������������
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//����������
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, NULL,
		g_hInstance, NULL );
	return hWnd;
}
//��ʾ����
void Display( HWND hWnd )
{
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
//��Ϣѭ��
void Message( )
{
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//����Ϣ�������ڴ�����
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



