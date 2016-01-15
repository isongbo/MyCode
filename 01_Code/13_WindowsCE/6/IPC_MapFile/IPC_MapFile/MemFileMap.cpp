// MemFileMap.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "MemFileMap.h"


// CMemFileMap

IMPLEMENT_DYNAMIC(CMemFileMap, CWnd)

/*
*构造函数，初始化类成员变量
*/
CMemFileMap::CMemFileMap()
{
  m_pMapPointer = NULL;
  m_hMapFile = NULL;
  m_hSynEvent = NULL ; 
  m_SynMessageID = -1;
  m_pParentWnd = NULL;
  m_Syn =false;
}


CMemFileMap::~CMemFileMap()
{
}


BEGIN_MESSAGE_MAP(CMemFileMap, CWnd)
END_MESSAGE_MAP()



// CMemFileMap 消息处理程序


/*
*函数介绍：创建或打开内存映射文件
*入口参数：(无)
*出口参数：(无)
*返回值：<=0 ,代表失败
*        >0,代表成功
*       -1 : 代表创建失败
*       -2 : 代表映射失败
*       -3 : 创建同步事件失败
*       -4 : 注册消息失败
*        1 : 代表创建成功，并且是新创建
*        2 : 代表打开成功，文件已存在
*/
DWORD CMemFileMap::OpenFileMap(CWnd * pWnd)
{
	DWORD returnValue = 1; //定义返回变量

    m_pParentWnd = pWnd;
    //创建内存映射文件
	m_hMapFile =CreateFileMapping(HANDLE(0xFFFFFFFF), NULL, 
		PAGE_READWRITE, 0,m_MaxSize,m_MapName.GetBuffer(m_MapName.GetLength()));  
	
	if ((m_hMapFile == INVALID_HANDLE_VALUE) || (m_hMapFile == 0))
	{
		return -1; //代表创建失败
	}

	if ((m_hMapFile != 0) && (GetLastError() == ERROR_ALREADY_EXISTS))
	{
		//内存文件，已创建
		returnValue = 2; //代表内存文件已打开
	}

	m_pMapPointer = (LPTSTR)MapViewOfFile(m_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (m_pMapPointer == NULL)
	{
		CloseHandle(m_hMapFile);
	    m_hMapFile = NULL;
        return -2;//'映射文件的视图到进程的地址空间失败')
	}

	m_hSynEvent = CreateEvent(NULL,FALSE,TRUE,_T("MEMFILE"));
	if (!m_hSynEvent)
	{
       UnmapViewOfFile(m_pMapPointer);
       m_pMapPointer = NULL;
	   CloseHandle(m_hMapFile);
	   m_hMapFile = NULL;
	   return -3;//创建同步事件失败
	}

	m_SynMessageID = RegisterWindowMessage(MEMFILECHANG);
	 if (!m_SynMessageID)
	 {
       UnmapViewOfFile(m_pMapPointer);
       m_pMapPointer = NULL;
	   CloseHandle(m_hMapFile);
	   m_hMapFile = NULL;
	   CloseHandle(m_hSynEvent);
	   m_hSynEvent = NULL;
	   return -4 ; //注册消息失败
	 }
  return returnValue;
}

/*
*函数介绍：关闭内存映射文件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CMemFileMap::CloseFileMap()
{
	if (m_pMapPointer)
	{
	  UnmapViewOfFile(m_pMapPointer);
      m_pMapPointer = NULL;
	}

	if (m_hMapFile)
	{
		CloseHandle(m_hMapFile);
		m_hMapFile = NULL;
	}

	if (m_hSynEvent)
	{
	   CloseHandle(m_hSynEvent);
	   m_hSynEvent = NULL;
	}
}


/*
*函数介绍：读取内存映射文件内容
*入口参数：(无)
*出口参数：(无)
*返回值：内存文件内容指针
*/
LPCTSTR CMemFileMap::ReadBuffer()
{
  return m_pMapPointer;
}

/*
*函数介绍：写入内存映射文件内容
*入口参数：buf :要写入的字符串数据指针
*出口参数：(无)
*返回值：-1 ：失败；1：成功
*/
DWORD CMemFileMap::WriteBuffer(LPCTSTR buf)
{
  if ((lstrlen(buf)) > m_MaxSize)
  {
	  return -1; //写入缓冲区，大于定义大小
  }
  //同步写过程，等待同步信号，且等到同步信号，自动关闭信号
  if (WaitForSingleObject(m_hSynEvent,INFINITE) == WAIT_OBJECT_0)
  {
    lstrcpy(m_pMapPointer,buf);
  }
 
  ::SendMessage(HWND_BROADCAST,m_SynMessageID,WPARAM(m_hWnd),0);
  //使同步事件有信号
  SetEvent(m_hSynEvent);
  return 1;
}

//消息处理函数
LRESULT CMemFileMap::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == m_SynMessageID)
	{
		//如果同步的话,就触发同步事件
		if (m_Syn)
		{
		  m_OnMemDataChange(m_pParentWnd);
		}
	}
	return CWnd::WindowProc(message, wParam, lParam);
}
