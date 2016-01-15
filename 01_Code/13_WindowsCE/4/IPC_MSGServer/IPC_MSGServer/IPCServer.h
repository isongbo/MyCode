#pragma once


// CIPCServer
//������Ϣ����
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//���������Ͽ�����ʱ
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//���ͻ��˶Ͽ�����ʱ
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//���ͻ�����������ʱ
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//���ͻ���������Ӧʱ

//�����������¼�
typedef void (CALLBACK* ONSERVERCONNECTED)(CWnd*,HWND);
//�������Ͽ��¼�
typedef void (CALLBACK* ONSERVERDISCONNECTED)(CWnd*,HWND);
//���������������¼�
typedef void (CALLBACK* ONSERVERDATAARRIVE)(CWnd*,LPVOID,DWORD,HWND);


class CIPCServer : public CWnd
{
	DECLARE_DYNAMIC(CIPCServer)

public:
	CIPCServer();
	virtual ~CIPCServer();

protected:
	DECLARE_MESSAGE_MAP()

private:
	bool m_Active; //�Ƿ񼤻�
    CWnd* m_ParentWnd; //ָ���������������ָ��
    DWORD m_SessionHandle; //���ӻỰ����Ϣ��ʶ��
    DWORD m_ServerDisConnectHwnd; //IPCServerDisconnecting��Ϣ��ʶ��
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest��Ϣ��ʶ��
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose��Ϣ��ʶ��
    DWORD m_ClientDisConnectHwnd; //IPCClientDisconnecting��Ϣ��ʶ��
public:
	LPCTSTR m_SessionName; //���ӻỰ������
	ONSERVERCONNECTED  m_ServerConnected; //�����������¼�
	ONSERVERDISCONNECTED m_ServerDisConnected; //�������Ͽ��¼�
	ONSERVERDATAARRIVE m_ServerDataArrive; //���������������¼�
public:
    //�򿪷����������м���
    void Open(CWnd* parentWnd);
    //�رշ�����
	void Close(void);
	//��������
    void SendMsg(LPVOID MsgPointer, HWND AWinHwnd, DWORD ASize);

protected:
	//��Ϣ��Ϣ������
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);


};


