/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� EricMediaControl.cpp
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
#include "StdAfx.h"
#include "EricMediaControl.h"

//���캯��
CEricMediaControl::CEricMediaControl(void)
{
	//��DSHOW�ӿ��ÿ�
	m_pGB = NULL;
	m_pMC = NULL;
	m_pME = NULL;
	m_pVW = NULL;
	m_pBA = NULL;
	m_pBV = NULL;
	m_pMS = NULL;
	//��ʼ�� COM ����
	CoInitialize(NULL); 
}

//��������
CEricMediaControl::~CEricMediaControl(void)
{
	//�ͷ�DSHOW�ӿ�
	UnInitDShow();
	//�ͷ�COM ����
	CoUninitialize();
}


/*
*�������ܣ� ��ʼ��DShow�ӿڣ�����Ⱦ����Ƶ�ļ�
*��ڲ����� strFileName:	��Ƶ�ļ���
			hOwnerWnd:		��ʾ��Ƶ�Ĵ��ھ��
			hNotifyWnd:		����DSHOW�¼���Ϣ�Ĵ��ھ��
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::InitDShow(LPCTSTR strFileName  /*��Ƶ�ļ���*/
		,HWND hOwnerWnd  /*��ʾ��Ƶ�Ĵ��ھ��*/
		,HWND hNotifyWnd /*����DSHOW�¼���Ϣ�Ĵ��ھ��*/
		)
{
	HRESULT hResult;
	//��1��������IGraphBuilder�ӿ�
	hResult = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&m_pGB);
	if (hResult != S_OK)
	{
		return FALSE;
	}
	//��2��������IGraphBuilder��Ⱦ��Ƶ�ļ�
	hResult = m_pGB->RenderFile(strFileName,NULL);
	if (hResult != S_OK )
	{
		//
		if (hResult == VFW_S_PARTIAL_RENDER)
		{
			TRACE(L"Some of the streams in this movie are in an unsupported format.\n");			
		}
		else if (hResult == VFW_S_AUDIO_NOT_RENDERED)
		{
			TRACE(L"Partial success; the audio was not rendered.\n");		
		}
		else if (hResult == VFW_S_DUPLICATE_NAME)
		{
			TRACE(L"Success; the Filter Graph Manager modified the filter name to avoid duplication..\n");	
		}
		else if (hResult == VFW_S_VIDEO_NOT_RENDERED)
		{
			TRACE(L"Partial success; some of the streams in this movie are in an unsupported format.\n");
		}
		else
		{
			//�ͷ�DSHOW�ӿ�
			UnInitDShow();
			return FALSE;
		}
	}
	//��3�����õ�ý�岥�ſ��ƽӿ�
	hResult = m_pGB->QueryInterface(IID_IMediaControl, (void **)&m_pMC); 
	if (hResult != S_OK)
	{
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	}
	//��4�����õ�ý�岥��λ�������ӿ�
	hResult = m_pGB->QueryInterface(IID_IMediaSeeking,(void**)&m_pMS);
	if (hResult != S_OK)
	{
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	}
	
	//���ò��Ҷ�λ��ʱ�䵥λ���������ã�100���루ʮ�ڷ�֮һ�룩
	GUID guid_timeFormat = TIME_FORMAT_MEDIA_TIME;
	m_pMS->SetTimeFormat(&guid_timeFormat);

	//��5�����õ�Filter Graphý���¼��ӿ�
	hResult = m_pGB->QueryInterface(IID_IMediaEventEx,(void**)&m_pME);
	if (hResult != S_OK)
	{
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	}
	//����ý���¼�֪ͨ��Ϣ����
	m_pME->SetNotifyWindow((OAHWND)hNotifyWnd, WM_GRAPHNOTIFY, 0);

	//��6�����õ���Ƶ���Ŵ��ڽӿ�
	 hResult = m_pGB->QueryInterface(IID_IVideoWindow, (void **)&m_pVW);
	 if (hResult != S_OK)
	 {
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	 }
	 //������Ƶ���Ŵ��ھ��
	 m_pVW->put_Owner((OAHWND)hOwnerWnd);
	 //������Ƶ���ڸ�ʽ
     m_pVW->put_WindowStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	 //��7�����õ�������Ƶ���ӿ�
	 hResult = m_pGB->QueryInterface(IID_IBasicVideo, (void **)&m_pBV);
  	 if (hResult != S_OK)
	 {
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	 }

	 //��8�����õ�������Ƶ���ӿ�
	 hResult = m_pGB->QueryInterface(IID_IBasicAudio, (void **)&m_pBA);
  	 if (hResult != S_OK)
	 {
		//�ͷ�DSHOW�ӿ�
		UnInitDShow();
		return FALSE;
	 }

	return TRUE;
}


/*
*�������ܣ� ж��DShowϵ�нӿ�
*��ڲ����� (��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::UnInitDShow()
{
	//1,�ͷ�ý�岥�ſ��ƽӿ�
	if (m_pMC != NULL)
	{
		//ֹͣ��Ƶ����
		m_pMC->Stop(); 
		m_pMC->Release();
		m_pMC = NULL;
	}
	
	//2,�ͷ�ý���¼��ӿ�
	if (m_pME != NULL)
	{
		//��Ϣ֪ͨ�����ÿ�
		m_pME->SetNotifyWindow(NULL, 0, 0);
		m_pME->Release();
		m_pME = NULL;
	}

	//3,�ͷ���Ƶ���Ŵ��ڽӿ�
	if (m_pVW != NULL)
	{
		//������Ƶ����
		m_pVW->put_Visible(OAFALSE);
		//������Ƶ���Ŵ��ھ��Ϊ��
		m_pVW->put_Owner(NULL);
		m_pVW->Release();
		m_pVW = NULL;
	}

	//4,�ͷŻ�����Ƶ���ӿ�
	if (m_pBA != NULL)
	{
		m_pBA->Release();
		m_pBA = NULL;
	}

	//5���ͷŻ�����Ƶ���ӿ�
	if (m_pBV != NULL)
	{
		m_pBV->Release();
		m_pBV = NULL;
	}

	//6���ͷ�ý�������ӿ�
	if (m_pMS != NULL)
	{
		m_pMS->Release();
		m_pMS = NULL;
	}

	//7,����ͷ�FilterGpaph�ӿ�
	if (m_pGB != NULL)
	{
		m_pGB->Release();
		m_pGB = NULL;
	}

	return TRUE;
}

/*
*�������ܣ�����Ƶ�ļ�
*��ڲ����� strFileName:	��Ƶ�ļ���
			hOwnerWnd:		��ʾ��Ƶ�Ĵ��ھ��
			hNotifyWnd:		����DSHOW�¼���Ϣ�Ĵ��ھ��
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�����Ƶ�ļ�;FALSE:����Ƶ�ļ�ʧ��
*/
BOOL CEricMediaControl::OpenFile(LPCTSTR strFileName /*��Ƶ�ļ���*/
		,HWND hOwnerWnd  /*��ʾ��Ƶ�Ĵ��ھ��*/
		,HWND hNotifyWnd /*����DSHOW�¼���Ϣ�Ĵ��ھ��*/
		)
{
	//�洢��ʾ��Ƶ���ھ��
	m_hOwnerWnd = hOwnerWnd;

	//����DSHOW�ӿ�
	UnInitDShow();

	//����Ƶ�ļ�������DSHOW�ӿ�����ʼ������
	return InitDShow(strFileName,hOwnerWnd,hNotifyWnd);
}

/*
*�������ܣ�������Ƶ
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::VideoRun()
{
	//���IMediaControl���ƽӿ���Ч��
	if (m_pMC == NULL)
	{
		return FALSE;
	}
	
	//������Ƶ
	HRESULT hResult = m_pMC->Run();
	if (hResult != S_OK)
	{
		return FALSE;
	}
	return TRUE;

}

/*
*�������ܣ���ͣ��Ƶ
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::VideoPause()
{
	//���IMediaControl���ƽӿ���Ч��
	if (m_pMC == NULL)
	{
		return FALSE;
	}

	//��ͣ��Ƶ
	HRESULT	hResult = m_pMC->Pause();
	if (hResult != S_OK)
	{
		return FALSE;
	}

	return TRUE;
}

/*
*�������ܣ�ֹͣ��Ƶ
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::VideoStop()
{
	HRESULT hResult	;
	//���IMediaControl���ƽӿ���Ч��
	if (m_pMC == NULL)
	{
		return FALSE;
	}
	
	//ֹͣ��Ƶ
	hResult = m_pMC->Stop();
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//����ǰ����λ����0
    LONGLONG pos=0;
	hResult = m_pMS->SetPositions(&pos, AM_SEEKING_AbsolutePositioning ,
                                   NULL, AM_SEEKING_NoPositioning);

	return TRUE;
}


/*
*�������ܣ�  ������Ƶ��ʾ����
*��ڲ�����  fScale �� ��ʾ����, <= 1.0
*���ڲ����� (��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ�ܣ��˴��е�����
*/
BOOL CEricMediaControl::FitVideoWindow(FLOAT fScale)
{
    LONG lHeight, lWidth;
	int iSeek = 0;
	double dblScaleX,dblScaleY;
    HRESULT hr = S_OK;
	LONG lDeflateX = 0;
	LONG lDeflateY = 0;
    CRect clientRect;
	CRect dstRect;
	
	//
	if (m_pBV == NULL)
	{
		return FALSE;
	}
	
	//������������С�ڵ���1
	if (fScale > 1.0)
	{
		return FALSE;
	}

	//�õ�ԭʼ��Ƶ�ߴ�
    hr = m_pBV->GetVideoSize(&lWidth, &lHeight);
	if (hr != S_OK)
	{
		return FALSE;
	}

	//���������ĳߴ�
	lWidth = lWidth * fScale;
	lHeight = lHeight * fScale;

	//�õ���Ƶ���Ŵ��ڵĳߴ�
	GetClientRect(m_hOwnerWnd, &clientRect);

	lDeflateX = (clientRect.Width() - clientRect.Width() * fScale) / 2;
	lDeflateY = (clientRect.Height() - clientRect.Height() * fScale) / 2;

	//�������ÿͻ�����
	clientRect.DeflateRect(lDeflateX,lDeflateY);

    
	if ( (lWidth <= clientRect.Width())
		&& (lHeight <= clientRect.Height()))
	{
		dstRect.left = (clientRect.right - clientRect.left - lWidth) /2;
		dstRect.right = dstRect.left + lWidth;
		dstRect.top  = (clientRect.bottom - clientRect.top - lHeight) /2;
		dstRect.bottom = dstRect.top + lHeight;
	}
	else 
	{
		dblScaleX =double(clientRect.Width()) / double(lWidth) ;
		dblScaleY =  double(clientRect.Height()) / double(lHeight) ;
		
		if (dblScaleX <= dblScaleY)
		{
			dstRect.left = clientRect.left;
			dstRect.right = clientRect.right;

			iSeek =(clientRect.Height() - clientRect.Width()*(double(lHeight) / double(lWidth)))/2;
			dstRect.top = clientRect.top + iSeek;
			dstRect.bottom = dstRect.top + clientRect.Width()*(double(lHeight) / double(lWidth));
		}
		else
		{
			dstRect.top = clientRect.top;
			dstRect.bottom = clientRect.bottom;

			iSeek =(clientRect.Width() - clientRect.Height()*(double(lWidth) / double(lHeight)))/2;
			dstRect.left = clientRect.left + iSeek;
			dstRect.right = dstRect.left + clientRect.Height()*(double(lWidth) / double(lHeight));
		}
	}

	//������Ƶ����λ��
    m_pVW->SetWindowPosition(dstRect.left,dstRect.top,dstRect.Width(),dstRect.Height());

    return TRUE;
}

/*
*�������ܣ�  ȫ����ʾ
*��ڲ����� (��)
*���ڲ����� (��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::FullScreen()
{
	LONG lMode = 0;
	static HWND hDrain=0;
	if (m_pBV == NULL)
	{
		return FALSE;
	}
	//�õ�ȫ��״̬
	m_pVW->get_FullScreenMode(&lMode);
	
	if (lMode == OAFALSE)
    {
		// Save current message drain
        m_pVW->get_MessageDrain((OAHWND *) &hDrain);

        // Set message drain to application main window
        m_pVW->put_MessageDrain((OAHWND)m_hOwnerWnd );
		
		//����ȫ��Ļ
        lMode = OATRUE;
        m_pVW->put_FullScreenMode(lMode);
    }
    else
    {
        //�л�����ȫ��ģʽ
        lMode = OAFALSE;
        m_pVW->put_FullScreenMode(lMode);

		 // Undo change of message drain
        m_pVW->put_MessageDrain((OAHWND) hDrain);
        // Reset video window
        FitVideoWindow(1);
        m_pVW->SetWindowForeground(-1);
	}
	return TRUE;
}

/*
*�������ܣ�  �õ��Ƿ�ȫ��Ļ����
*��ڲ����� (��)
*���ڲ����� (��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::GetFullScreenStatus()
{
	LONG lMode = 0;
	if (m_pBV == NULL)
	{
		return FALSE;
	}

	m_pVW->get_FullScreenMode(&lMode);

	if (lMode == OAFALSE)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*
*�������ܣ�  �õ�ý���¼�
*��ڲ����� (��)
*���ڲ����� lEventCode
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::GetMediaEvent(long *lEventCode)
{
    LONG evCode, evParam1, evParam2;
    HRESULT hr=S_OK;

	if (m_pME == NULL)
	{
		return FALSE;
	}

	hr = m_pME->GetEvent(&evCode, &evParam1, &evParam2, 0);
    if (SUCCEEDED(hr))
	{
        *lEventCode = evCode;
		// Spin through the events
        hr = m_pME->FreeEventParams(evCode, evParam1, evParam2);
		
		return TRUE;
	}
	return FALSE;
}


/*
*�������ܣ�  ���ò��Ž���
*��ڲ����� dwPos �����Ž��ȣ���λ��
*���ڲ����� (��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::SetPositions(DWORD dwPos /*���õ�ǰ���Ž���*/)
{
	//���þ���λ��,ת��������Ϊ��λ
	LONGLONG llPos = dwPos * 10000 * 1000;
	if (m_pMS == NULL)
	{
		return FALSE;
	}
	//������Ƶ���ŵ�ǰλ��
	HRESULT hr = m_pMS->SetPositions(&llPos,AM_SEEKING_AbsolutePositioning ,
                                   NULL, AM_SEEKING_NoPositioning);
	if (hr == S_OK)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
*�������ܣ�  �õ���Ƶ�ļ����ų���,��λ��
*��ڲ����� dwLength ����Ƶ�ļ�ʱ�䳤��
*���ڲ����� dwLength ����Ƶ�ļ�ʱ�䳤��
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::GetDuration(DWORD &dwLength)
{	
	dwLength = 0;
	if (m_pMS == NULL)
	{
		return FALSE;
	}

	//�õ���Ƶ��ʱ�䳤��
	LONGLONG llDuration;
	HRESULT hResult = m_pMS->GetDuration(&llDuration);
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//ת��������Ϊ��λ
	llDuration = llDuration / 10000 ;
	llDuration = llDuration / 1000;
	dwLength  = (DWORD)llDuration;
	return TRUE;
}

/*
*�������ܣ�  �õ�ý�嵱ǰ���Ž���λ��,��λ��
*��ڲ����� dwPos ����ǰ���Ž��ȣ���λ��
*���ڲ����� dwPos ����ǰ���Ž��ȣ���λ��
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricMediaControl::GetCurrentPos(DWORD &dwPos)
{
	dwPos = 0;
	LONGLONG llPos = 0;
	if (m_pMS== NULL)
	{
		return FALSE;
	}
	
	//�õ���ǰ��Ƶ����λ��
	HRESULT hResult = m_pMS->GetCurrentPosition(&llPos);
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//ת��������Ϊ��λ
	llPos = llPos / 10000 ;
	llPos = llPos / 1000;
	dwPos  = (DWORD)llPos;
	return TRUE;
}