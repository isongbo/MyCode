#include "stdafx.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
HMENU hFile;
void OnCreate( HWND hWnd )
{
	HMENU hMain = CreateMenu( );

	hFile = CreatePopupMenu( );
	AppendMenu( hFile, MF_STRING|MF_CHECKED, 1003, "�½�" );
	AppendMenu( hFile, MF_SEPARATOR, 0, "" );
	AppendMenu( hFile, MF_STRING|MF_MENUBARBREAK, 1004, "�˳�" );

	HMENU hHelp = CreatePopupMenu( );
	AppendMenu( hHelp, MF_STRING|MF_GRAYED, 1005, "����" );

	AppendMenu( hMain, MF_POPUP, (UINT)hFile, "�ļ�" );
	AppendMenu( hMain, MF_POPUP, (UINT)hHelp, "����" );
	SetMenu( hWnd, hMain );
}
int g_state = 0;//��־�����½��˵����״̬��
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1003:
		if( g_state==0 )
			CheckMenuItem( hFile, 1003, 
					MF_BYCOMMAND|MF_UNCHECKED );
		else
			CheckMenuItem( hFile, 0,
					MF_BYPOSITION|MF_CHECKED );
		g_state = !g_state;
		break;
	case 1004:
		MessageBox( hWnd, "�˳������", "Infor", MB_OK );
		break;
	case 1005:
		MessageBox( hWnd, "���ڱ����", "Infor", MB_OK );
		break;
	}
}
//���ڴ���������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_CREATE:
		OnCreate( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );//����ʹGetMessage����0
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
	wce.lpszMenuName = NULL;
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
		DispatchMessage( &nMsg );//����Ϣ�������ڴ�������
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


