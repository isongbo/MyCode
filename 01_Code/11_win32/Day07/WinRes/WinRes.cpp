#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_NEW:
		if( HIWORD(wParam)==0 )
			MessageBox(hWnd,"�½��˵�����","Infor",MB_OK);
		else if( HIWORD(wParam)==1 )
			MessageBox(hWnd,"CTRL+M�����","Infor",MB_OK);
		break;
	case ID_SET:
		MessageBox(hWnd, "CTRL+Y�����", "Infor", MB_OK );
		break;
	}
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );
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
	HACCEL hAccel = LoadAccelerators( g_hInstance, 
				MAKEINTRESOURCE(IDR_ACCELERATOR1) );
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		if(!TranslateAccelerator(nMsg.hwnd,hAccel,&nMsg))
		{
			TranslateMessage( &nMsg );		
			DispatchMessage( &nMsg );//����Ϣ�������ڴ�����
		}
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	char szTitle[256] = { 0 };
	LoadString( hInstance, IDS_WND, szTitle, 256 );
	HWND hWnd = CreateMain( "Main", szTitle );
	Display( hWnd );
	Message( );
	return 0;
}



