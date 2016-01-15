#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void SysReg( )
{ 
	//不需要注册
	HWND hWnd = CreateWindow( "BUTTON", "OK", WS_OVERLAPPEDWINDOW,
				100, 100, 500, 500, NULL, NULL, 
				g_hInstance, NULL );
	ShowWindow( hWnd, SW_SHOW );
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;
	SysReg( );
	return 0;
}



