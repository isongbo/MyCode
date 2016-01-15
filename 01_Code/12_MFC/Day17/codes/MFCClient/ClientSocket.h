#if !defined(AFX_CLIENTSOCKET_H__1F43C19F_23CC_4123_BCF3_7ED21F59862A__INCLUDED_)
#define AFX_CLIENTSOCKET_H__1F43C19F_23CC_4123_BCF3_7ED21F59862A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();
	//1 初始化客户端(创建、连接)
	BOOL InitClient(char* IP,UINT nPort);
  //2 发送文件
	BOOL SendFile(CString strPath);
	//3 发送数据
	BOOL SendData(BYTE* pData,long nLen);

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__1F43C19F_23CC_4123_BCF3_7ED21F59862A__INCLUDED_)
