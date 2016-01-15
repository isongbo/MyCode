#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_NEW:
		if( HIWORD(wParam)==0 )
			MessageBox(hWnd,"新建菜单项被点击","Infor",MB_OK);
		else if( HIWORD(wParam)==1 )
			MessageBox(hWnd,"CTRL+M被点击","Infor",MB_OK);
		break;
	case ID_SET:
		MessageBox(hWnd, "CTRL+Y被点击", "Infor", MB_OK );
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
	HACCEL hAccel = LoadAccelerators( g_hInstance, 
				MAKEINTRESOURCE(IDR_ACCELERATOR1) );
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		if(!TranslateAccelerator(nMsg.hwnd,hAccel,&nMsg))
		{
			TranslateMessage( &nMsg );		
			DispatchMessage( &nMsg );//将消息交给窗口处理函数
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



