#include "stdafx.h"
//自定义函数（处理消息，体面名字窗口处理函数）
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );//可以使GetMessage返回0？？
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam );
			//给各种消息做默认处理
}	
					 
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	//注册窗口类（向操作系统中写入一些数据）
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hInstance;/******************/
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Main";/******************/
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass( &wc );//将以上所有赋值全部写入操作系统
	
	//内存中创建窗口(申请一块内存，往内存扔窗口数据)
	HWND hWnd = CreateWindow( "Main", "window", 
				WS_OVERLAPPEDWINDOW, 100, 100, 500, 500,
				NULL, NULL, hInstance, NULL );
	//显示窗口（在显示器根据内存中的数据绘制窗口的图像）
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
	//消息循环
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//将消息交给自定义函数
	}
	return 0;
}



