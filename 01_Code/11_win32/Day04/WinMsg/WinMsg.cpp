#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
HANDLE g_hOutput = 0;//���ձ�׼������
HWND g_hEdit = 0;//���ձ༭��ؼ��ľ��
#define WM_MYMESSAGE WM_USER+1001
void OnCreate( HWND hWnd, LPARAM lParam )
{
	CREATESTRUCT *pcs = (CREATESTRUCT*)lParam;
	char *pszText = (char*)pcs->lpCreateParams;
	MessageBox( hWnd, pszText, "Infor", MB_OK );
	g_hEdit = CreateWindowEx( 0, "EDIT", "hello", 
			WS_CHILD|WS_VISIBLE|WS_BORDER, 0, 0, 200, 200,
			hWnd, NULL, g_hInstance, NULL );
	SendMessage( hWnd, WM_MYMESSAGE, 1, 2 );
}
void OnSize( HWND hWnd, LPARAM lParam )
{
	int nWidth = LOWORD(lParam);//���
	int nHight = HIWORD(lParam);//�߶�
	char szText[256] = { 0 };
	sprintf( szText, "��=%d,��=%d\n", nWidth, nHight );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
	MoveWindow( g_hEdit, 0, 0, nWidth-10, nHight-10, TRUE );
}
void OnMyMessage( HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText,"�Զ�����Ϣ������wParam=%d,lParam=%d",
				wParam, lParam );
	MessageBox( hWnd, szText, "Infor", MB_OK );
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_MYMESSAGE:
		OnMyMessage( hWnd, wParam, lParam );
		break;
	case WM_SIZE:
		OnSize( hWnd, lParam );
		break;
	case WM_CREATE:
		OnCreate( hWnd, lParam );
		break;
	case WM_DESTROY:
//		PostQuitMessage( 0 );
		PostMessage( hWnd, WM_QUIT, 0, 0 );
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
	char *pszText = "hello data";
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, NULL,
		g_hInstance, pszText );
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
/*	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//����Ϣ�������ڴ�����
	}*/
	while( 1 )
	{
		if( PeekMessage(&nMsg, NULL, 0, 0, PM_NOREMOVE) )
		{
			//����Ϣ
			if( GetMessage( &nMsg, NULL, 0, 0 ) )
			{
				TranslateMessage( &nMsg );
				DispatchMessage( &nMsg );
			}else{
				return;
			}
		}else{
			//���д���
			WriteConsole( g_hOutput, "OnIdle", 6, NULL,
							NULL );
		}
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	AllocConsole( );
	g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



