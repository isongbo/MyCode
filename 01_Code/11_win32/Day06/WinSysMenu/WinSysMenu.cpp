#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCreate( HWND hWnd )
{
	HMENU hSys = GetSystemMenu( hWnd, FALSE );
	for( int i=0; i<6; i++ )
	{
		DeleteMenu( hSys, 0, MF_BYPOSITION );
	}
	AppendMenu( hSys, MF_SEPARATOR, 0, "" );
	AppendMenu( hSys, MF_STRING, 1001, "我的菜单项" );
}
void OnSysCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1001:
		MessageBox( hWnd, "我的菜单项被点击",
					"Infor", MB_OK );
		break;
	}
}
void OnRButtonUp( HWND hWnd, LPARAM lParam )
{
/*	HMENU hPopup = CreatePopupMenu( );
	AppendMenu( hPopup, MF_STRING, 1002, "新建" );
	AppendMenu( hPopup, MF_SEPARATOR, 0, "" );
	AppendMenu( hPopup, MF_STRING, 1003, "退出" );
	
	POINT pt = { 0 };
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);//保存了客户区坐标系下光标位置
	ClientToScreen( hWnd, &pt );//转换坐标

	BOOL nRet = TrackPopupMenu( hPopup,
		TPM_CENTERALIGN|TPM_VCENTERALIGN|TPM_RETURNCMD, 
		pt.x, pt.y, 0, hWnd, NULL );
	switch( nRet )
	{
	case 1002:
		MessageBox( hWnd, "没发COMMAND消息处理新建被点击",
					"Infor", MB_OK );
		break;
	case 1003:
		MessageBox( hWnd, "没发COMMAND消息处理退出被点击",
					"Infor", MB_OK );

		break;
	}*/
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1002:
		MessageBox( hWnd, "窗口处理函数处理新建被点击",
			"Infor", MB_OK );
		break;
	case 1003:
		MessageBox( hWnd, "窗口处理函数处理退出被点击",
						"Infor", MB_OK );
		break;
	}
}
void OnContextMenu( HWND hWnd, LPARAM lParam )
{
	HMENU hPopup = CreatePopupMenu( );
	AppendMenu( hPopup, MF_STRING, 1002, "新建" );
	AppendMenu( hPopup, MF_SEPARATOR, 0, "" );
	AppendMenu( hPopup, MF_STRING, 1003, "退出" );
	
	POINT pt = { 0 };
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);//保存了客户区坐标系下光标位置
//	ClientToScreen( hWnd, &pt );//不需要转换
	
	BOOL nRet = TrackPopupMenu( hPopup,
		TPM_CENTERALIGN|TPM_VCENTERALIGN|TPM_RETURNCMD, 
		pt.x, pt.y, 0, hWnd, NULL );
	switch( nRet )
	{
	case 1002:
		MessageBox( hWnd, "没发COMMAND消息处理新建被点击",
			"Infor", MB_OK );
		break;
	case 1003:
		MessageBox( hWnd, "没发COMMAND消息处理退出被点击",
			"Infor", MB_OK );
		
		break;
	}
}
//窗口处理函数（处理消息）
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_CONTEXTMENU:
		OnContextMenu( hWnd, lParam );
		break;
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_RBUTTONUP:
		OnRButtonUp( hWnd, lParam );
		break;
	case WM_SYSCOMMAND:
		OnSysCommand( hWnd, wParam );
		break;
	case WM_CREATE:
		OnCreate( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );
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
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



