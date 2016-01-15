#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
HANDLE g_hOutput = 0;//接收标准输出句柄
HWND g_hEdit = 0;//接收编辑框控件的句柄
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
	int nWidth = LOWORD(lParam);//宽度
	int nHight = HIWORD(lParam);//高度
	char szText[256] = { 0 };
	sprintf( szText, "宽=%d,高=%d\n", nWidth, nHight );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
	MoveWindow( g_hEdit, 0, 0, nWidth-10, nHight-10, TRUE );
}
void OnMyMessage( HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText,"自定义消息被处理wParam=%d,lParam=%d",
				wParam, lParam );
	MessageBox( hWnd, szText, "Infor", MB_OK );
}
//窗口处理函数（处理消息）
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
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//创建主窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	char *pszText = "hello data";
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, NULL,
		g_hInstance, pszText );
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
/*	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//将消息交给窗口处理函数
	}*/
	while( 1 )
	{
		if( PeekMessage(&nMsg, NULL, 0, 0, PM_NOREMOVE) )
		{
			//有消息
			if( GetMessage( &nMsg, NULL, 0, 0 ) )
			{
				TranslateMessage( &nMsg );
				DispatchMessage( &nMsg );
			}else{
				return;
			}
		}else{
			//空闲处理
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



