#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
int g_kind = 0;//��־��������WM_PAINT��Ϣ��������ͼ�Σ�
void OnCommand( HWND hWnd, WPARAM wParam )
{
	g_kind = LOWORD(wParam);
	switch( LOWORD(wParam) )
	{
	case ID_PIT:
	case ID_LINE:
	case ID_REC:
	case ID_ELL:
	case ID_ARC:
	case ID_BMP:
		InvalidateRect( hWnd, NULL, TRUE );
		break;
	}
}
void DrawPit( HDC hdc )
{
//	SetPixel( hdc, 100, 100, RGB(255,0,0) );
	for( int i=0; i<256; i++ )
	{
		for( int j=0; j<256; j++ )
		{
			SetPixel( hdc, i, j, RGB(i,j,0) );
		}
	}
}
void DrawLine( HDC hdc )
{
	MoveToEx( hdc, 100, 100, NULL );
	LineTo( hdc, 300, 300 );
	LineTo( hdc, 0, 300 );
	LineTo( hdc, 100, 100 );
}
void DrawRec( HDC hdc )
{
	Rectangle( hdc, 100, -100, 300, -300 );
	RoundRect( hdc, 300, 100, 500, 300, 200, 200 );
}
void DrawEll( HDC hdc )
{
	Ellipse( hdc, 100, 100, 300, 300 );
	Ellipse( hdc, 300, 100, 600, 300 );
}
void DrawArc( HDC hdc )
{
	SetArcDirection( hdc, AD_CLOCKWISE );//˳ʱ��ȡ��
	Arc( hdc, 100, 100, 300, 300, 100, 100, 300, 300 );
}
void DrawBmp( HDC hdc )
{
	//���λͼ��Դ
	HBITMAP hBmp = LoadBitmap( g_hInstance, 
				MAKEINTRESOURCE(IDB_BITMAP1) );
	BITMAP bmpInfo = { 0 };
	GetObject( hBmp, sizeof(bmpInfo), &bmpInfo );
	HDC hMemdc = CreateCompatibleDC( hdc );
	//����һ���ڴ�DC,ͬʱ����һ����������
	//����һ���ڴ�DC(�ں˽ṹ)��ͬʱ����һ���ڴ�
	HGDIOBJ nOldBmp = SelectObject( hMemdc, hBmp );
	//��ͼ��ÿ�������ɫֵ�͸��ڴ�DC,�ڴ�DC������ͼ�����
	//������������
	//��ͼ��ÿ�������ɫֵ�ӵ� �ڴ�DCά�����ڴ�
	BitBlt( hdc, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,
			hMemdc, 0, 0, SRCCOPY );
	//1:1����
	//���ڴ�DCά�����ڴ��е����ݣ����ڴ濽����ʽһ����
	//�ӵ���ǰDC ά���Դ��С�
	StretchBlt( hdc, 100, 100, 96, 96, 
				hMemdc, 0, 0, bmpInfo.bmWidth,
				bmpInfo.bmHeight, SRCCOPY );
	//���ų���
	SelectObject( hMemdc, nOldBmp );
	DeleteObject( hBmp );
	DeleteDC( hMemdc );
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	HPEN hPen = CreatePen( PS_DASH, 1, RGB(255,0,0) );
	HGDIOBJ nOldPen = SelectObject( hdc, hPen );
	
//	HBRUSH hBrush = CreateSolidBrush(RGB(0,255,0) );
//	HBRUSH hBrush = CreateHatchBrush( HS_CROSS, RGB(0,255,0) );
//	HGDIOBJ hBrush = GetStockObject( NULL_BRUSH );
	HBITMAP hBmp = LoadBitmap( g_hInstance,
					MAKEINTRESOURCE(IDB_BITMAP1) );
	HBRUSH hBrush = CreatePatternBrush( hBmp );
	HGDIOBJ nOldBrush = SelectObject( hdc, hBrush );

	int nOldMode = SetMapMode( hdc, MM_ISOTROPIC );
	SetWindowExtEx( hdc, 1, -1, NULL );
	SetViewportExtEx( hdc, 2, -3, NULL );
	switch( g_kind )
	{
	case ID_BMP:
		DrawBmp( hdc );//����λͼ
		break;
	case ID_ARC:
		DrawArc( hdc );//���ƻ���
		break;
	case ID_ELL:
		DrawEll( hdc );//����Բ��
		break;
	case ID_REC:
		DrawRec( hdc );//���ƾ���
		break;
	case ID_LINE:
		DrawLine( hdc );//����ֱ��
		break;
	case ID_PIT:
		DrawPit( hdc );//���Ƶ�
		break;
	}
	SetMapMode( hdc, nOldMode );
	SelectObject( hdc, nOldBrush );
	DeleteObject( hBrush );
	SelectObject( hdc, nOldPen );
	DeleteObject( hPen );
	EndPaint( hWnd, &ps );
}
//���ڴ�������������Ϣ��
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
						 WPARAM wParam, LPARAM lParam )
{
	switch( msgID )
	{
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
	wce.hbrBackground = CreateSolidBrush( RGB(0,0,255) );
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndproc;//������������
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx( &wce );
}
//����������
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName,
		lpWndName, WS_OVERLAPPEDWINDOW,
		100, 100, 700, 500, NULL, NULL,
		g_hInstance, NULL );
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



