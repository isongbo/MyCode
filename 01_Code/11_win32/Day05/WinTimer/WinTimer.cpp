#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
HANDLE g_hOutput = 0;
int g_xPos = 100;
int g_yPos = 100;
BOOL Left_Right = TRUE;
BOOL Right_Left = FALSE;
BOOL Up_Down = TRUE;
BOOL Down_Up = FALSE;
void OnTimer( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf(szText, "窗口处理函数处理定时器:%d\n",wParam);
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
	RECT rc = { 0 };
	GetClientRect( hWnd, &rc );//获取窗口边界信息
	if( g_xPos >= rc.right-50 )
	{
		Right_Left = TRUE;
		Left_Right = FALSE;
	}else if( g_xPos<= rc.left )
	{
		Left_Right = TRUE;
		Right_Left = FALSE;
	}

	if( Left_Right==TRUE )
	{
		g_xPos++;
	}else if( Right_Left==TRUE )
	{
		g_xPos--;
	}

	if( g_yPos >= rc.bottom-50 )
	{
		Down_Up = TRUE;
		Up_Down = FALSE;
	}else if( g_yPos <= rc.top )
	{
		Up_Down = TRUE;
		Down_Up = FALSE;
	}

	if( Up_Down==TRUE )
	{
		g_yPos++;
	}else if( Down_Up==TRUE )
	{
		g_yPos--;
	}
	InvalidateRect( hWnd, NULL, FALSE );
}
//定时器处理函数(只能处理定时器消息)
void CALLBACK TimerProc( HWND hWnd, UINT msgID,
						UINT timeID, DWORD dwTime )
{
	char szText[256] = { 0 };
	sprintf( szText, "定时器处理函数处理定时器:%d\n",
						timeID );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	Ellipse( hdc, g_xPos, g_yPos, g_xPos+50, g_yPos+50 );
	EndPaint( hWnd, &ps );
}
//窗口处理函数（处理消息）
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_LBUTTONDOWN:
		KillTimer( hWnd, 1 );
		break;
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_TIMER:
		OnTimer( hWnd, wParam );
		break;
	case WM_CREATE:
		SetTimer( hWnd, 1, 10, NULL );
//		SetTimer( hWnd, 2, 2000, TimerProc );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );//可以使GetMessage返回0
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
	AllocConsole( );
	g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



