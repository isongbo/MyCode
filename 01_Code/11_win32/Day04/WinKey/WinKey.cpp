#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
HANDLE g_hOutput = 0;
int g_xPos = 100;
int g_yPos = 100;
void OnPaint( HWND hWnd )
{
	char *pszText = "WM_PAINT\n";
//	WriteConsole( g_hOutput, pszText, strlen(pszText),
//					NULL, NULL );
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	TextOut( hdc, g_xPos, g_yPos, "hello", 5 );
	EndPaint( hWnd, &ps );
	/*�������ڻ�ͼ�Ĵ���������WM_PAINT��Ϣ�����е���*/
}
void OnKeyDown( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_KEYDOWN:%08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
	switch( wParam )
	{
	case VK_UP:
		g_yPos--;
		break;
	case VK_DOWN:
		g_yPos++;
		break;
	case VK_LEFT:
		g_xPos--;
		break;
	case VK_RIGHT:
		g_xPos++;
		break;
	}
	InvalidateRect( hWnd, NULL, TRUE );
}
void OnKeyUp( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_KEYUP:%08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
void OnChar( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_CHAR:%08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_CHAR:
		OnChar( hWnd, wParam );
		break;
	case WM_KEYDOWN:
		OnKeyDown( hWnd, wParam );
		break;
	case WM_KEYUP:
		OnKeyUp( hWnd, wParam );
		break;
	case WM_LBUTTONDOWN:
		InvalidateRect( hWnd, NULL, TRUE );
		break;
	case WM_PAINT:
		OnPaint( hWnd );
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



