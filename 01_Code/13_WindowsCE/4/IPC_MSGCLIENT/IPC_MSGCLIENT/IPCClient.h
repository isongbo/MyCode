#pragma once


// CIPCClient
//������Ϣ����
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//���������Ͽ�����ʱ
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//���ͻ��˶Ͽ�����ʱ
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//���ͻ�����������ʱ
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//���ͻ���������Ӧʱ

//�ͻ��������¼�
typedef void (CALLBACK* ONCLIENTCONNECTED)(CWnd*,HWND);
//�ͻ��˶Ͽ��¼�
typedef void (CALLBACK* ONCLIENTDISCONNECTED)(CWnd*,HWND);
//�ͻ��˽��������¼�
typedef void (CALLBACK* ONCLIENTDATAARRIVE)(CWnd*,LPVOID,DWORD);

class CIPCClient : public CWnd
{
	DECLARE_DYNAMIC(CIPCClient)

public:
	CIPCClient();
	virtual ~CIPCClient();

protected:
	DECLARE_MESSAGE_MAP()
private:
	HWND m_ServerWinHwnd; //����˴�����
	CWnd* m_ParentWnd; ////ָ������������Ĵ���ָ��
	bool m_Active; //�Ƿ񼤻�
	DWORD m_SessionHandle; //���ӻỰ����Ϣ��ʶ��
	DWORD m_ServerDisconnectHwnd; //IPCServerDisconnecting��Ϣ��ʶ��
	DWORD m_ConnectRequestHwnd; //IPCConnectRequest��Ϣ��ʶ��
	DWORD m_ConnectResposeHwnd; //IPCConnectRespose��Ϣ��ʶ��
	DWORD m_ClientDisconnectHwnd; //IPCClientDisconnecting��Ϣ��ʶ��
public:
	LPCTSTR m_SessionName; // ���ӻỰ������
	ONCLIENTCONNECTED  m_ClientConnected; //�ͻ��������¼�
	ONCLIENTDISCONNECTED m_ClientDisConnected; //�ͻ��˶Ͽ������¼�
	ONCLIENTDATAARRIVE m_ClientDataArrive; //�ͻ��˽��������¼�

public:
      //ͬ��������������
	void Open(CWnd *parentWnd);
    //�ر�ͬ����������
	void Close(void);
	//��������
	void SendMsg(LPVOID MsgPointer,  DWORD ASize);
protected:
	//��Ϣ��Ϣ������
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

};


