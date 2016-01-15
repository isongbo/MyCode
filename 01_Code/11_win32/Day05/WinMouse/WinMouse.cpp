#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
HANDLE g_hOutput = 0;
int g_xPos = 100;
int g_yPos = 100;
void OnLButtonDown(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText, 
			"WM_LBUTTONDOWN:����״̬:%08X, x=%d,y=%d\n",
				wParam, LOWORD(lParam), HIWORD(lParam) );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
void OnLButtonUp( HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText, 
			"WM_LBUTTONUP:����״̬:%08X, x=%d, y=%d\n",
				wParam, LOWORD(lParam), HIWORD(lParam) );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
void OnMouseMove( HWND hWnd, LPARAM lParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_MOUSEMOVE:X=%d, Y=%d\n",
				LOWORD(lParam), HIWORD(lParam) );
//	WriteConsole( g_hOutput, szText, strlen(szText),
//					NULL, NULL );
	g_xPos = LOWORD(lParam);
	g_yPos = HIWORD(lParam);
	InvalidateRect( hWnd, NULL, FALSE );
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	TextOut( hdc, g_xPos, g_yPos, "hello", 5 );
	EndPaint( hWnd, &ps );
}
void OnLButtonDblClk( HWND hWnd )
{
	char *pszText = "WM_LBUTONDBLCLK\n";
	WriteConsole( g_hOutput, pszText, strlen(pszText),
					NULL, NULL );
}
void OnMouseWheel( HWND hWnd, WPARAM wParam )
{
	short nDelta = HIWORD(wParam);//ƫ����
	char szText[256] = { 0 };
	sprintf( szText, "ƫ����=%d\n", nDelta );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_MOUSEWHEEL:
		OnMouseWheel( hWnd, wParam );
		break;
	case WM_LBUTTONDBLCLK:
		OnLButtonDblClk( hWnd );
		break;
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_MOUSEMOVE:
		OnMouseMove( hWnd, lParam );
		break;
	case WM_LBUTTONDOWN:
		OnLButtonDown( hWnd, wParam, lParam );
		break;
	case WM_LBUTTONUP:
		OnLButtonUp( hWnd, wParam, lParam );
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
	wce.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
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
	AllocConsole( );
	g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



