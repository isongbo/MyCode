#pragma once

//定义内存文件内容变化消息字符串
const LPCTSTR  MEMFILECHANG = _T("MEMFILECHANGE");
//定义内存映射内容改变事件
typedef void (CALLBACK* ONMEMDATACHANGE)(CWnd*);

// CMemFileMap

class CMemFileMap : public CWnd
{
	DECLARE_DYNAMIC(CMemFileMap)

public:
	CMemFileMap();
	virtual ~CMemFileMap();

protected:
	DECLARE_MESSAGE_MAP()
public:
	//创建或打开内存映射文件
	DWORD OpenFileMap(CWnd * pWnd);
	//关闭映射文件
	void CloseFileMap();
	//读取内存文件信息
	LPCTSTR ReadBuffer();
	//写入内存文件信息
	DWORD WriteBuffer(LPCTSTR buf);
public:
	//windows 消息处理函数
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) ;


private:
	HANDLE m_hMapFile; //内存映射文件句柄
	LPTSTR m_pMapPointer ; //内存文件映射数据句柄
	HANDLE m_hSynEvent ; //写内存文件时，同步事件句柄
	DWORD m_SynMessageID ;//同步消息
	CWnd  * m_pParentWnd ; //指定创建此类的窗体指针
public:
	DWORD m_MaxSize ; //内存文件大小
	CString m_MapName; //内存映射文件名称
	bool m_Syn; //是否同步
	ONMEMDATACHANGE m_OnMemDataChange; //内存映射区内容改变事件

};


