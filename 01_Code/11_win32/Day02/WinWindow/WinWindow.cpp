#include "stdafx.h"
//�Զ��庯����������Ϣ���������ִ��ڴ�������
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );//����ʹGetMessage����0����
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam );
			//��������Ϣ��Ĭ�ϴ���
}	
					 
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	//ע�ᴰ���ࣨ�����ϵͳ��д��һЩ���ݣ�
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
	RegisterClass( &wc );//���������и�ֵȫ��д�����ϵͳ
	
	//�ڴ��д�������(����һ���ڴ棬���ڴ��Ӵ�������)
	HWND hWnd = CreateWindow( "Main", "window", 
				WS_OVERLAPPEDWINDOW, 100, 100, 500, 500,
				NULL, NULL, hInstance, NULL );
	//��ʾ���ڣ�����ʾ�������ڴ��е����ݻ��ƴ��ڵ�ͼ��
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
	//��Ϣѭ��
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );//����Ϣ�����Զ��庯��
	}
	return 0;
}



