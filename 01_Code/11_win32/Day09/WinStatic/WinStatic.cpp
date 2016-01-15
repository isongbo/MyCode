#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCreate( HWND hWnd )
{
	CreateWindowEx( 0, "STATIC", "hello txt", 
			WS_CHILD|WS_VISIBLE|SS_NOTIFY,
			100, 100, 200, 50, hWnd, (HMENU)1001,
			g_hInstance, NULL );
	CreateWindowEx( 0, "STATIC", "#101",
			WS_CHILD|WS_VISIBLE|SS_ICON|SS_NOTIFY,
			400, 100, 0, 0, hWnd, (HMENU)1002,
			g_hInstance, NULL );
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1001:
		if( HIWORD(wParam)==STN_CLICKED )
		{
			MessageBox(hWnd, "认错认了", "Infor", MB_OK );
		}
		break;
	case 1002:
		if( HIWORD(wParam)==STN_DBLCLK )
		{
			MessageBox(hWnd, "打死你", "Infor", MB_OK );
		}
		break;
	case ID_BLACK:
		{
			HICON hBlack = LoadIcon( g_hInstance,
							MAKEINTRESOURCE(IDI_ICON1) );
			HWND hStatic = GetDlgItem( hWnd, 1002 );
			SendMessage( hStatic, STM_SETICON,
								(WPARAM)hBlack, 0 );
		}
		break;
	case ID_BLUE:
		{
			HICON hBlue = LoadIcon( g_hInstance,
							MAKEINTRESOURCE(IDI_ICON2) );
			HWND hStatic = GetDlgItem( hWnd, 1002 );
			SendMessage( hStatic, STM_SETICON,
								(WPARAM)hBlue, 0 );
		}
		break;
	}
}
//窗口处理函数（处理消息）
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
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;//参数传递来的
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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



