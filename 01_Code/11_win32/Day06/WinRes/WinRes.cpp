#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_NEW:
		MessageBox( hWnd, "�½������", "Infor", MB_OK );
		break;
	case ID_EXIT:
		MessageBox( hWnd, "�˳������", "Infor", MB_OK );
		break;
	case ID_ABOUT:
		MessageBox( hWnd, "���ڱ����", "Infor", MB_OK );
		break;
	}
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	HICON hIcon = LoadIcon( g_hInstance, 
						MAKEINTRESOURCE(IDI_ICON1) );
	DrawIcon( hdc, 100, 100, hIcon );
	EndPaint( hWnd, &ps );
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
	case WM_SETCURSOR:
		{
//			HCURSOR hRec = LoadCursor( g_hInstance,
//							MAKEINTRESOURCE(IDC_CURSOR1));
//			HCURSOR hBall = LoadCursor( g_hInstance,
//							MAKEINTRESOURCE(IDC_CURSOR2));
			HCURSOR hRec = LoadCursorFromFile(
					"c:/windows/Cursors/dinosau2.ani" );
			HCURSOR hBall = LoadCursorFromFile(
					"c:/windows/Cursors/dinosaur.ani" );
			if( LOWORD(lParam)==HTCLIENT )
			{
				POINT pt = { 0 };
				GetCursorPos( &pt );//��Ļ����ϵ�����λ�ã�
				ScreenToClient( hWnd, &pt );//ת������
				RECT rc = { 0 };
				GetClientRect(hWnd,&rc);//�ͻ�������ϵ���߽���Ϣ��
				if( pt.x <= rc.right/2 )
					SetCursor( hBall );
				else
					SetCursor( hRec );				
				return 0;
			}else{
				//ʲô����д	
			}			
		}
		break;
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );//����ʹGetMessage����0����
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
	wce.hCursor = LoadCursor( g_hInstance,
					MAKEINTRESOURCE(IDC_CURSOR1) );
	wce.hIcon = LoadIcon( g_hInstance, 
					MAKEINTRESOURCE(IDI_ICON1) );
	wce.hIconSm = LoadIcon( g_hInstance,
					MAKEINTRESOURCE(IDI_ICON2) );
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;//������������
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//����������
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HMENU hMenu = LoadMenu( g_hInstance, 
						MAKEINTRESOURCE(IDR_MENU1) );
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, hMenu,
		g_hInstance, NULL );
	HICON hIcon = LoadIcon( g_hInstance,
					MAKEINTRESOURCE(IDI_ICON1) );
	SendMessage( hWnd, WM_SETICON, 
						ICON_SMALL, (LPARAM)hIcon );
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
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}



