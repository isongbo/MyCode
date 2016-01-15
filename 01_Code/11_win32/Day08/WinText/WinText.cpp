#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	
	SetTextColor( hdc, RGB(255,0,0) );
	SetBkColor( hdc, RGB(0,255,0) );//只适用于OPAQUE模式
	SetBkMode( hdc, TRANSPARENT );
	
	HFONT hFont = CreateFont( 30, 0, 45, 0, 900, 1, 1, 1, 
			GB2312_CHARSET, 0, 0, 0, 0, "黑体" );
	HGDIOBJ nOldFont = SelectObject( hdc, hFont );

	char szText[] = "hello&txt";
	TextOut( hdc, 100, 100, szText, strlen(szText) );

	RECT rc = { 0 };
	rc.left = 100;
	rc.top = 150;
	rc.right = 200;
	rc.bottom = 200;
//	Rectangle( hdc, 100, 150, 200, 200 );
	DrawText( hdc, szText, strlen(szText), &rc,
				DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOCLIP|
				DT_NOPREFIX );
	//DT_VCENTER/DT_BOTTOM - 只适用于DT_SINGLELINE
	//                       不适用于DT_WORDBREAK

	char szExtText[] = "A中国人民";
	int nDis[] = { 10,0,20,0,30,0,40,0 };
	ExtTextOut( hdc, 100, 300, 0, NULL, szExtText,
					strlen(szExtText), nDis );
	SelectObject( hdc, nOldFont );
	DeleteObject( hFont );
	EndPaint( hWnd, &ps );
}
//窗口处理函数（处理消息）
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );//可以使GetMessage返回0？？
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam );
			//给各种消息做默认处理
}
//注册窗口类
void Register( LPSTR lpClassName, WNDPROC wndproc )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+3);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;//参数传递来的
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//创建主窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, NULL,
		g_hInstance, NULL );
	return hWnd;
}
//显示窗口
void Display( HWND hWnd )
{
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
//消息循环
void Message( )
{
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//将消息交给窗口处理函数
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



