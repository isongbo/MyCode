#if !defined(AFX_SERVERSOCKET_H__F2CB1719_55F5_4EEE_9790_68D260A41BE0__INCLUDED_)
#define AFX_SERVERSOCKET_H__F2CB1719_55F5_4EEE_9790_68D260A41BE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target

class CServerSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CServerSocket();
	virtual ~CServerSocket();
  //��ʼ��������(�������󶨡�����)
	BOOL InitServer(UINT nPort);
  // ��������
	BOOL RecvData(CSocket& client,BYTE* pData,
		            long nLen);
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__F2CB1719_55F5_4EEE_9790_68D260A41BE0__INCLUDED_)
