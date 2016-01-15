#include "stdafx.h"
#include "resource.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnCreate( HWND hWnd )
{
	CreateWindowEx( 0, "COMBOBOX", "Simple",
			WS_CHILD|WS_VISIBLE|CBS_SIMPLE|WS_VSCROLL,
			50, 50, 200, 200, hWnd, (HMENU)1001,
			g_hInstance, NULL );
	CreateWindowEx( 0, "COMBOBOX", "DropDown",
			WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|WS_VSCROLL,
			260, 50, 200, 200, hWnd, (HMENU)1002,
			g_hInstance, NULL );
	CreateWindowEx( 0, "COMBOBOX", "DropList",
			WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|WS_VSCROLL,
			470, 50, 200, 200, hWnd, (HMENU)1003,
			g_hInstance, NULL );
}
void OnAdd( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	HWND hDropDown = GetDlgItem( hWnd, 1002 );
	HWND hDropList = GetDlgItem( hWnd, 1003 );
	for( int i=0; i<100; i++ )
	{
		char szText[256] = { 0 };
		sprintf( szText, "Item%d", i );
		SendMessage( hSimple, CB_ADDSTRING, 0,
						(LPARAM)szText );
		SendMessage( hDropDown, CB_ADDSTRING, 0,
						(LPARAM)szText );
		SendMessage( hDropList, CB_ADDSTRING, 0, 
						(LPARAM)szText );
		char *pszText = "hello data";
		SendMessage(hSimple, CB_SETITEMDATA, i, 
							(LPARAM)pszText );
	}
	SendMessage( hSimple, CB_SETCURSEL, 99, 0 );
	SendMessage( hDropDown, CB_SETCURSEL, 99, 0 );
	SendMessage( hDropList, CB_SETCURSEL, 99, 0 );
}
void OnClear( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	HWND hDropDown = GetDlgItem( hWnd, 1002 );
	HWND hDropList = GetDlgItem( hWnd, 1003 );
	SendMessage( hSimple, CB_RESETCONTENT, 0, 0 );
	SendMessage( hDropDown, CB_RESETCONTENT, 0, 0 );
	SendMessage( hDropList, CB_RESETCONTENT, 0, 0 );
}
void OnDelete( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	HWND hDropDown = GetDlgItem( hWnd, 1002 );
	HWND hDropList = GetDlgItem( hWnd, 1003 );
	LRESULT nSel=SendMessage(hSimple, CB_GETCURSEL, 0, 0);
	if( nSel != CB_ERR )
	{
		SendMessage( hSimple,CB_DELETESTRING,nSel,0 );
	}
	nSel = SendMessage(hDropDown,CB_GETCURSEL,0,0);
	if( nSel != CB_ERR )
	{
		SendMessage(hDropDown,CB_DELETESTRING,nSel,0);
	}
	nSel = SendMessage(hDropList,CB_GETCURSEL,0,0);
	if( nSel != CB_ERR )
	{
		SendMessage(hDropList,CB_DELETESTRING,nSel,0);
	}
}
void OnFind( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	char *pszText = "Item";
	LRESULT nFind = SendMessage( hSimple, 
			CB_SELECTSTRING, -1, (LPARAM)pszText );
	if( nFind != CB_ERR )
	{
		char szFind[256] = { 0 };
		sprintf( szFind, "ƥ���ѡ�%d", nFind );
		MessageBox( hWnd, szFind, "Infor", MB_OK );
	}else{
		MessageBox( hWnd, "ƥ��ʧ��", "Infor", MB_OK );
	}
	/*
	CB_FINDSTRING - �Ǿ�ȷƥ����ң����Բ�ȫ�����ܴ�
	CB_FINDSTRINGEXACT - ��ȷƥ�����
	CB_SELECTSTRING - �Ǿ�ȷƥ����ң����Բ�ȫ�����ܴ�,
	                  ����ƥ�䵽��ѡ������Ϊ��ǰѡ����
	*/
}
void OnText( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	LRESULT nSel = SendMessage(hSimple,CB_GETCURSEL,0,0);
	if( nSel != CB_ERR )
	{
		char szText[256] = { 0 };
		SendMessage( hSimple, CB_GETLBTEXT, nSel,
							(LPARAM)szText );
		MessageBox( hWnd, szText, "Infor", MB_OK );
	}else{
		MessageBox( hWnd, "��ѡ����", "Infor", MB_OK );
	}
	
	char szText[256] = { 0 };
	SendMessage(hSimple, WM_GETTEXT, 256, (LPARAM)szText);
	MessageBox( hWnd, szText, "Infor", MB_OK );
}
void OnData( HWND hWnd )
{
	HWND hSimple = GetDlgItem( hWnd, 1001 );
	LRESULT nSel = SendMessage( 
					hSimple, CB_GETCURSEL, 0, 0 );
	if( nSel != CB_ERR )
	{
		LRESULT nData = SendMessage( hSimple,
						CB_GETITEMDATA, nSel, 0 );
		char szText[256] = { 0 };
		sprintf( szText, "��������:%s", (char*)nData );
		MessageBox( hWnd, szText, "Infor", MB_OK );
	}
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case 1001:
		if( HIWORD(wParam)==CBN_SELCHANGE )
		{
			HWND hSimple = GetDlgItem( hWnd, 1001 );
			HWND hDropDown = GetDlgItem( hWnd, 1002 );
			HWND hDropList = GetDlgItem( hWnd, 1003 );
			LRESULT nSel = SendMessage( hSimple,
								CB_GETCURSEL, 0, 0 );
			SendMessage(hDropDown,CB_SETCURSEL,nSel,0);
			SendMessage(hDropList,CB_SETCURSEL,nSel,0);
		}else if( HIWORD(wParam)==CBN_EDITCHANGE )
		{
			MessageBox(hWnd,"�������������б仯","Infor",
						MB_OK );
		}
		break;
	case ID_DATA:
		OnData( hWnd );//��ȡѡ����ĸ�������
		break;
	case ID_TEXT:
		OnText( hWnd );//��ȡѡ�����ı�����
		break;
	case ID_FIND:
		OnFind( hWnd );//ƥ��ѡ��
		break;
	case ID_DELETE:
		OnDelete( hWnd );//ɾ��ѡ����
		break;
	case ID_CLEAR:
		OnClear( hWnd );//���ѡ��
		break;
	case ID_ADD:
		OnAdd( hWnd );//���ѡ��
		break;
	}
}
//���ڴ�������������Ϣ��
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



