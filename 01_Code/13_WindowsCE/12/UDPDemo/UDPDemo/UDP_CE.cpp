/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� UDP_CE.cpp
* �ļ���ʶ�� 
* ժҪ�����ڷ�װWINCE UDPͨѶ
*
* ��ǰ�汾�� 1.0
* ���ߣ� ���� Eric Wong
* ������ڣ� 2008��1��18��
*
* ȡ���汾��
* ԭ���ߣ� 
* ������ڣ� 
----------------------------------------*/
#include "StdAfx.h"
#include "UDP_CE.h"

//���캯��
CUDP_CE::CUDP_CE(void)
{
	m_UDPSocket = 0;                   	//UDP SocketͨѶ�׽���
	m_pOwner = NULL;                  	//�洢��������
	ZeroMemory(m_recvBuf,4096) ;		//�������ݻ�����
	m_OnUdpError = NULL;				//UDP���������¼�
	m_OnUdpRecv = NULL;					//UDP���������¼�
}

//��������
CUDP_CE::~CUDP_CE(void)
{
}

/*
*�������ܣ���UDPͨѶ�˿�
*��ڲ�����pOwner: ָ��������ָ�� 
           localPort: ָ��Զ��UDP�˿�
           romoteHost:ָ��Զ��IP��ַ
           remotePort:ָ��Զ��UDP�˿�
*���ڲ�����(��)
*����ֵ��1����ɹ���-1��-2��-3�ȶ�����ʧ��
*/
DWORD CUDP_CE::Open(void* pOwner,int localPort,LPCTSTR remoteHost,int remotePort)
{
	WSADATA wsa;
	//���ݸ�����ָ��
	m_pOwner = pOwner;
	//����winsock��̬���ӿ�
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		return -1;//����ʧ��
	}
	//����UDP�׽���
	m_UDPSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (m_UDPSocket == INVALID_SOCKET)
	{
		return -2;
	}
	
	//���ñ��ص�ַ
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(localPort);
	localAddr.sin_addr.s_addr=INADDR_ANY;
	
	//�󶨵�ַ
	if(bind(m_UDPSocket,(sockaddr*)&localAddr,sizeof(localAddr))!=0)
	{
		return -3;
	}
	
	//���÷Ƕ���ͨѶ
	DWORD ul= 1;
	ioctlsocket(m_UDPSocket,FIONBIO,&ul);

	//����һ���߳��˳��¼�
	m_ExitThreadEvent	= CreateEvent(NULL,TRUE,FALSE,NULL);
	
	//����ͨѶ�߳�
	AfxBeginThread(RecvThread,this);
	
	//���öԷ���ַ
	m_RemoteAddr.sin_family = AF_INET;
	m_RemoteAddr.sin_port = htons(remotePort);
	//�˴�Ҫ��˫�ֽ�ת���ɵ��ֽ�
	char ansiRemoteHost[255];
	ZeroMemory(ansiRemoteHost,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,remoteHost,wcslen(remoteHost)
		,ansiRemoteHost,wcslen(remoteHost),NULL,NULL);
	m_RemoteAddr.sin_addr.s_addr=inet_addr(ansiRemoteHost);

	return 1;
}

/*
*�������ܣ��ر�UDPͨѶ�˿�
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��1����ɹ���-1��-2�ȶ�����ʧ��
*/
DWORD CUDP_CE::Close(void)
{
	//����ͨѶ�߳��˳��¼���֪ͨ�߳��˳�
	SetEvent(m_ExitThreadEvent);
	Sleep(1000);
	//�ر��߳̾��
	CloseHandle(m_ExitThreadEvent);
	//�ر�socket
	if (closesocket(m_UDPSocket) == SOCKET_ERROR)
	{
		return -1;
	}
	
	//�ͷ�socket��Դ
	if (WSACleanup() == SOCKET_ERROR)
	{
		return -2;
	}

	return 1;
}

/*
*�������ܣ���������
*��ڲ�����buf:����������
           len:�������ݳ���
*���ڲ�����(��)
*����ֵ�����ͳɹ�����ʵ�ʷ��͵��ֽ��������򷵻�-1
*/
DWORD CUDP_CE::SendData(const char *buf, int len)
{
	int nBytes = 0; //ÿ�η��ͳ�ȥ���ֽ�
	int nSendBytes=0;  //�Ѿ����ͳ�ȥ���ֽ�
	int nErrorCode =0; //������
	
	//��������
	while (nSendBytes < len)
	{
		//��������
		nBytes = sendto(m_UDPSocket,buf+nSendBytes,len-nSendBytes,0,(sockaddr*)&m_RemoteAddr,sizeof(m_RemoteAddr));
		if (nBytes==SOCKET_ERROR )
		{
			nErrorCode = WSAGetLastError();
			if (m_OnUdpError)
			{
				m_OnUdpError(m_pOwner,nErrorCode);
			}
			return -1;
		}
		//ȫ���������
		if (nSendBytes == len)
		{
			break;
		}
		//ѭ������
		Sleep(500);
		nSendBytes = nSendBytes + nBytes;
	}
	return nSendBytes;
}

/*
*�������ܣ������̺߳���
*��ڲ�����lparam : ָ�����̵߳Ĳ���
*���ڲ�����(��)
*�� �� ֵ�������塣
*/
UINT CUDP_CE::RecvThread(LPVOID lparam)
{
	//
	CUDP_CE *pSocket = (CUDP_CE*)lparam;
	fd_set fdRead;
	int ret;
	TIMEVAL	aTime;
	aTime.tv_sec = 1;
	aTime.tv_usec = 0;
	SOCKADDR_IN tmpAddr;
	int tmpRecvLen;
	int recvLen;
	int iErrorCode;
	
	while (TRUE)
	{
        //�յ��˳��¼��������߳�
		if (WaitForSingleObject(pSocket->m_ExitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}
		//��set��ʼ���ռ���
		FD_ZERO(&fdRead);
		//��pSocket->m_UDPSocket�׽�����ӵ�������
		FD_SET(pSocket->m_UDPSocket,&fdRead);
		//����select�������ж��׽���I/O״̬
		ret = select(0,&fdRead,NULL,NULL,&aTime);	
		if (ret == SOCKET_ERROR)
		{
			iErrorCode = WSAGetLastError();
			if (pSocket->m_OnUdpError)
			{
				pSocket->m_OnUdpError(pSocket->m_pOwner,iErrorCode);
			}
			break;
		}
		
		//���¼�����
		if (ret > 0)
		{
			//�յ�����
			if (FD_ISSET(pSocket->m_UDPSocket,&fdRead))
			{		
				//
                tmpAddr.sin_family=AF_INET;             
                tmpAddr.sin_port = htons(pSocket->m_RemoteAddr.sin_port);
				tmpAddr.sin_addr.s_addr =INADDR_ANY;
                tmpRecvLen = sizeof(tmpAddr);

				//�ÿս��ջ�����
				ZeroMemory(pSocket->m_recvBuf,4096);
				//��������
				recvLen = recvfrom(pSocket->m_UDPSocket,pSocket->m_recvBuf, 4096,0,(SOCKADDR*)&tmpAddr,&tmpRecvLen); 
				if (recvLen == SOCKET_ERROR)
				{
					iErrorCode = WSAGetLastError();
					if (pSocket->m_OnUdpError)
					{
						pSocket->m_OnUdpError(pSocket->m_pOwner,iErrorCode);
					}
				}
				else if (recvLen == 0)
				{
					iErrorCode = WSAGetLastError();
					if (pSocket->m_OnUdpError)
					{
						pSocket->m_OnUdpError(pSocket->m_pOwner,iErrorCode);	
					}
				}
				else
				{
					//���ûص����������ݷ��ͳ�ȥ
					if (pSocket->m_OnUdpRecv)
					{
						pSocket->m_OnUdpRecv(pSocket->m_pOwner,pSocket->m_recvBuf,recvLen,(SOCKADDR*)&tmpAddr);
					}
				}	

			}
		}
	}
	TRACE(L"The read thread had exited.\n");
	return 0;
}
