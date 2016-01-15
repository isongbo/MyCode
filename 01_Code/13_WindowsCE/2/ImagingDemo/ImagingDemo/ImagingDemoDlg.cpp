// ImagingDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "ImagingDemo.h"
#include "ImagingDemoDlg.h"

#include "initguid.h"
#include <Imaging.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImagingDemoDlg �Ի���

CImagingDemoDlg::CImagingDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImagingDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImagingDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImagingDemoDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_IMAGESHOW, &CImagingDemoDlg::OnBnClickedBtnImageshow)
	ON_BN_CLICKED(IDC_BTN_ENUM, &CImagingDemoDlg::OnBnClickedBtnEnum)
	ON_BN_CLICKED(IDC_BTN_CHANGE, &CImagingDemoDlg::OnBnClickedBtnChange)
END_MESSAGE_MAP()


// CImagingDemoDlg ��Ϣ�������

BOOL CImagingDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CImagingDemoDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_IMAGINGDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_IMAGINGDEMO_DIALOG));
	}
}
#endif

//��ʾͼƬ
void CImagingDemoDlg::OnBnClickedBtnImageshow()
{
	HRESULT hr ; //���ؽ��
	IImagingFactory * pImagingFactory =NULL; //Image�����ӿڶ���
	IImage * pImage = NULL;	//Image�ӿڶ���
	LPCTSTR szFileName = L"\\test.jpg"; //ͼ���ļ�

	//��ʼ��COM����
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//�õ�Image�����ӿڶ���
     hr = CoCreateInstance(CLSID_ImagingFactory, 
                          NULL, 
                          CLSCTX_INPROC_SERVER, 
                          IID_IImagingFactory, 
                          (void**) &pImagingFactory);

    if (FAILED(hr))
	{
		TRACE(L"IMAGE FACTORY CREATED ERROR");
		goto finish;
	}

	//����ͼ���ļ���IImage�ӿڶ�����
	hr = pImagingFactory->CreateImageFromFile(szFileName,&pImage);

	//
	if (FAILED(hr))
	{
		TRACE(L"IMAGE LOAD ERROR");
		goto finish;
	}	

	//��ʼ����ͼ��
	//�õ��豸����
	CDC *pDC =GetDC();

	//������Ƴߴ�
	RECT rect;
	GetClientRect(&rect);

	//����ͼƬ
	pImage->Draw(pDC->m_hDC, &rect, NULL);

	//�ͷ��豸����
	ReleaseDC(pDC);

finish:
	//�ͷ�IImage�ӿڶ���
    if (pImage)
        pImage->Release();
        
	//�ͷ�IImagingFactory�ӿڶ���
    if (pImagingFactory)
        pImagingFactory->Release();

	//�ͷų���ռ�õ�COM��Դ
    CoUninitialize();


}

//ö��
void CImagingDemoDlg::OnBnClickedBtnEnum()
{
	HRESULT hr ; //���ؽ��
	IImagingFactory * pImagingFactory = NULL ; //Image�����ӿڶ���
	UINT uCount = 0;  
    ImageCodecInfo * Encodecs = NULL; //�洢������INFO�б�
    ImageCodecInfo * Decodecs= NULL ; //�洢������INFO�б�

	BSTR   strGLSID;//

	//��ʼ��COM����
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//�õ�Image�����ӿڶ���
     hr = CoCreateInstance(CLSID_ImagingFactory, 
                          NULL, 
                          CLSCTX_INPROC_SERVER, 
                          IID_IImagingFactory, 
                          (void**) &pImagingFactory);

    if (FAILED(hr))
	{
		TRACE(L"IMAGE FACTORY CREATED ERROR");
		goto finish;
	}

	//ö�ٱ���������б�
	pImagingFactory->GetInstalledEncoders(&uCount,&Encodecs);

	//
	TRACE(L"Enum Encoder compents...............\n");
	TRACE(L"-------------------------------------------\n");
	for (int i = 0; i< uCount ; i++)
	{
		TRACE(L"CodecName : %s \n", Encodecs[i].CodecName);
		TRACE(L"MimeType: %s \n",Encodecs[i].MimeType);

		StringFromCLSID(Encodecs[i].Clsid,&strGLSID);
		TRACE(L"Clisd: %s \n",strGLSID);
		TRACE(L"-------------------------------------------\n");
	}

	//�ͷ��ڴ�
    CoTaskMemFree(Encodecs);

	//ö�ٽ���������б�
	pImagingFactory->GetInstalledDecoders(&uCount,&Decodecs);

	TRACE(L"Enum Decoder compents...............\n");
	TRACE(L"-------------------------------------------\n");
	for (int i = 0; i< uCount ; i++)
	{

		TRACE(L"CodecName : %s \n", Decodecs[i].CodecName);
		TRACE(L"MimeType: %s \n",Decodecs[i].MimeType);

		StringFromCLSID(Decodecs[i].Clsid,&strGLSID);
		TRACE(L"Clisd: %s \n",strGLSID);
		TRACE(L"-------------------------------------------\n");
	}

	//�ͷ��ڴ�
    CoTaskMemFree(Decodecs);

finish:
	//�ͷ�IImagingFactory�ӿڶ���
    if (pImagingFactory)
        pImagingFactory->Release();

	//�ͷų���ռ�õ�COM��Դ
    CoUninitialize();

}

/*
*�������ܣ����ļ����ص��ڴ�����
*��ڲ�����tszFilename����ʾҪ�򿪵��ļ�
*���ڲ����� ppStream : ��ʾ�ڴ��������ļ��е�������������ڴ�����
*����ֵ��S_OK :��ʾ�ɹ�������ʧ��
*/
HRESULT CreateStreamOnFile(const TCHAR * tszFilename, IStream ** ppStream)
{
    HRESULT hrRet = S_FALSE;
    HGLOBAL hg = NULL;
    HANDLE hFile = NULL;
    DWORD dwSize, dwRead;
    BYTE* pbLocked = NULL;

    //���ļ�
    hFile = CreateFile(tszFilename, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
    {
        goto error;
    }

	//�õ��ļ���С
    dwSize = GetFileSize(hFile, NULL);
    if (0xffffffff == dwSize)
    {
        goto error;
    }

    //�����ڴ�
    hg = GlobalAlloc(GMEM_MOVEABLE, dwSize);
    if (NULL == hg)
    {
        goto error;
    }

    //�õ��Ѿ�������ڴ�ָ��
    pbLocked = (BYTE*) GlobalLock(hg);
    if (NULL == pbLocked)
    {
        goto error;
    }

    //��ȡ�ļ����ݵ��ڴ���
    if (!ReadFile(hFile, pbLocked, dwSize, &dwRead, NULL))
    {
        goto error;
    }

	//�����Ѿ�����ȫ���ڴ棬��ӦGlobalLock(hg)
    GlobalUnlock(hg);
    
    //����Stream����
    hrRet = CreateStreamOnHGlobal(hg, TRUE, ppStream);

	//�ر��ļ���
    CloseHandle(hFile);
    return hrRet;
error: //������,���ͷ��ڴ�
    if (pbLocked)
        GlobalUnlock(hg);
    if (hg)
        GlobalFree(hg);
    if (hFile)
        CloseHandle(hFile);
    return hrRet;
}

/*
*�������ܣ����ݱ������������ƣ��õ�ָ���ı�����CLSID
*��ڲ�����pImagingFactory: Image�����ӿڶ���
           wszMimeType : Image�����ʽ����  
*���ڲ�����pclsid :��������CLSID
*����ֵ��TRUE : �ɹ�; FALSE: ʧ��
*/
BOOL GetEnCodecCLSID(IImagingFactory* pImagingFactory,WCHAR * wszMimeType ,CLSID * pclsid )
{
    UINT uiCount;
    ImageCodecInfo * codecs;
    HRESULT hr;
    BOOL fRet = FALSE;

	//ö��ϵͳ�Ѿ���װ�ı�����
	hr = pImagingFactory->GetInstalledEncoders(&uiCount, &codecs);

	//�����ƶ���������CLSID
    for (UINT i = 0; i < uiCount; i++)
    {
        if (wszMimeType && !wcscmp(wszMimeType, codecs[i].MimeType))
        {
            *pclsid = codecs[i].Clsid;
            fRet = TRUE;
            break;
        }
    }
	//�ͷ��ڴ�
    CoTaskMemFree(codecs);
	//
    return fRet;
}

//��ʽת��
void CImagingDemoDlg::OnBnClickedBtnChange()
{
		//���ڽ�test.jpgת����test.gif
		HRESULT hr;
		IImagingFactory * pImagingFactory = NULL ; //Image�����ӿڶ���
		IStream *pStream = NULL;	// ���ӿڶ���
		IImageSink *pImageSink = NULL; //Image Sink�ӿڶ���
		IImageDecoder *pImageDecoder = NULL;   //�������ӿڶ���
		IImageEncoder *pImageEncoder = NULL;	//�������ӿڶ���
		CLSID clsidEncoder;  //������CLSID
		TCHAR *tszInFileName, *tszOutFileName, *tszMime;

		tszInFileName = L"\\test.bmp";  //ָ����ת����ͼ���ļ�
		tszOutFileName = L"\\test.jpg"; //ָ��ת�����ͼ���ļ�
		tszMime = L"image/jpeg";	   //ָ��ת����ͼ���ļ��ĸ�ʽ

		//��ʼ��COM����
		if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
		{
       		TRACE(L"COINIT_MULTITHREADED ERROR");
			return;
		}

		//�õ�Image�����ӿڶ���
		 hr = CoCreateInstance(CLSID_ImagingFactory, 
							  NULL, 
							  CLSCTX_INPROC_SERVER, 
							  IID_IImagingFactory, 
							  (void**) &pImagingFactory);

		if (FAILED(hr))
		{
			TRACE(L"IMAGE FACTORY CREATED ERROR");
			goto finish;
		}	


		//���ļ����ݼ��ص�����
        if (FAILED(hr = CreateStreamOnFile(tszInFileName, &pStream)))
        {
            goto finish;
        }

		//���ݱ������������Ƶõ�������CLSID
        if (!GetEnCodecCLSID(pImagingFactory,tszMime, &clsidEncoder ))
        {
            goto finish;
        }

		//�����������ӿڣ�������������ļ���
        if (FAILED(hr = pImagingFactory->CreateImageEncoderToFile(&clsidEncoder, tszOutFileName, &pImageEncoder)))
        {
            goto finish;
        }

		//�����������ӿ�
        if (FAILED(hr = pImagingFactory->CreateImageDecoder(pStream, DecoderInitFlagBuiltIn1st, &pImageDecoder)))
        {
            goto finish;
        }

		//�õ��������ӿڵ�sink���󡣴�ImageSink�ӿ���Ϊһ���ۻ��߹ܵ�����⣻
		//�����ڸ���pImageEncoder��pImageDecoder֮��Ĵ���
        if (FAILED(hr = pImageEncoder->GetEncodeSink(&pImageSink)))
        {
            goto finish;
        }

        //��ʼ����
        if (FAILED(hr = pImageDecoder->BeginDecode(pImageSink, NULL)))
        {
            goto finish;
        }

		//ѭ�����룬ֱ������
        for(;;)
        {
			//����
            hr = pImageDecoder->Decode();
			//�����������Ĳ���
            if (E_PENDING == hr)
            {
                Sleep(500);
            }
			//ʧ��
            else if (FAILED(hr))
            {
				//��ֹ����
                pImageDecoder->EndDecode(hr);
                goto finish;
            }
            else
            {
				//����ɹ�
                break;
            }
        }
		//��������
        pImageDecoder->EndDecode(hr);

		//�ͷ�pImageSink����
        pImageSink->Release();
        pImageSink = NULL;

		//�������룬��ʱ���Ѿ�������ļ���ʽ��ת��
        pImageEncoder->TerminateEncoder();

finish:
        
	//�ͷ�pStream����
    if (pStream)
        pStream->Release();
        
	//�ͷ�pImageSink����
    if (pImageSink)
        pImageSink->Release();

	//�ͷ�pImageDecoder����
    if (pImageDecoder)
        pImageDecoder->Release();

	//�ͷ�pImageEncoder����
    if (pImageEncoder)
        pImageEncoder->Release();

	//�ͷ�IImagingFactory�ӿڶ���
    if (pImagingFactory)
        pImagingFactory->Release();

	//�ͷų���ռ�õ�COM��Դ
    CoUninitialize();

}
