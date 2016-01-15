/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� EricMediaControl.h
* �ļ���ʶ�� 
* ժҪ�����ڷ�װDSHOW ������Ƶ�ļ�
*
* ��ǰ�汾�� 1.0
* ���ߣ� ���� Eric Wong
* ������ڣ� 2008��2��2��
*
* ȡ���汾��
* ԭ���ߣ� 
* ������ڣ� 
----------------------------------------*/
#pragma once


#include <dshow.h>

//����DSHOW �¼�֪ͨ��Ϣ
#define WM_GRAPHNOTIFY  WM_USER + 101

class CEricMediaControl
{
public:
	CEricMediaControl(void);
	~CEricMediaControl(void);

private:
	//DSHOW �ӿ�
	IGraphBuilder *m_pGB ;  
	IMediaControl *m_pMC ;
	IMediaEventEx *m_pME ;
	IVideoWindow  *m_pVW ;
	IBasicAudio *m_pBA ;
	IBasicVideo   *m_pBV ;
	IMediaSeeking *m_pMS ;

	//��ʾ��Ƶ�Ĵ��ھ��
	HWND m_hOwnerWnd;
private:
	//��ʼ��DSHOW�ӿ�
	BOOL InitDShow(LPCTSTR strFileName  /*��Ƶ�ļ���*/
		,HWND hOwnerWnd  /*��ʾ��Ƶ�Ĵ��ھ��*/
		,HWND hNotifyWnd /*����DSHOW�¼���Ϣ�Ĵ��ھ��*/
		);
	//�ͷ�DSHOW�ӿ�
	BOOL UnInitDShow();
public:
	//����Ƶ�ļ�
	BOOL OpenFile(LPCTSTR strFileName /*��Ƶ�ļ���*/
		,HWND hOwnerWnd  /*��ʾ��Ƶ�Ĵ��ھ��*/
		,HWND hNotifyWnd /*����DSHOW�¼���Ϣ�Ĵ��ھ��*/
		);
	//������Ƶ
	BOOL VideoRun();
	//��ͣ��Ƶ
	BOOL VideoPause();
	//ֹͣ��Ƶ
	BOOL VideoStop();
public:
	//������Ƶ��ʾ����
	BOOL FitVideoWindow(FLOAT fScale);
	//ȫ����ʾ
	BOOL FullScreen();
	//�õ��Ƿ���ȫ����ʾ
	BOOL GetFullScreenStatus();
	//�õ�DShow�����¼�
	BOOL GetMediaEvent(long *lEventCode);
	//���ò��Ž��ȣ���λ: ��
	BOOL SetPositions(DWORD dwPos /*���õ�ǰ���Ž���*/);
	//�õ���Ƶ���ŵ�ǰ��λ�ã���λ����
	BOOL GetCurrentPos(DWORD &dwPos  /*out ��ǰ���Ž���*/);
	//�õ���Ƶ�ļ�ʱ�䳤�ȣ���λ����
	BOOL GetDuration(DWORD &dwLength);
};
