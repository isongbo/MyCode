// ImagingDemoDlg.cpp : 实现文件
//

#include "stdafx.h"

#include "ImagingDemo.h"
#include "ImagingDemoDlg.h"

#include "initguid.h"
#include <Imaging.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImagingDemoDlg 对话框

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


// CImagingDemoDlg 消息处理程序

BOOL CImagingDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

//显示图片
void CImagingDemoDlg::OnBnClickedBtnImageshow()
{
	HRESULT hr ; //返回结果
	IImagingFactory * pImagingFactory =NULL; //Image工厂接口对象
	IImage * pImage = NULL;	//Image接口对象
	LPCTSTR szFileName = L"\\test.jpg"; //图象文件

	//初始化COM环境
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//得到Image工厂接口对象
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

	//加载图象文件到IImage接口对象中
	hr = pImagingFactory->CreateImageFromFile(szFileName,&pImage);

	//
	if (FAILED(hr))
	{
		TRACE(L"IMAGE LOAD ERROR");
		goto finish;
	}	

	//开始绘制图象
	//得到设备环境
	CDC *pDC =GetDC();

	//定义绘制尺寸
	RECT rect;
	GetClientRect(&rect);

	//绘制图片
	pImage->Draw(pDC->m_hDC, &rect, NULL);

	//释放设备环境
	ReleaseDC(pDC);

finish:
	//释放IImage接口对象
    if (pImage)
        pImage->Release();
        
	//释放IImagingFactory接口对象
    if (pImagingFactory)
        pImagingFactory->Release();

	//释放程序占用的COM资源
    CoUninitialize();


}

//枚举
void CImagingDemoDlg::OnBnClickedBtnEnum()
{
	HRESULT hr ; //返回结果
	IImagingFactory * pImagingFactory = NULL ; //Image工厂接口对象
	UINT uCount = 0;  
    ImageCodecInfo * Encodecs = NULL; //存储编码器INFO列表
    ImageCodecInfo * Decodecs= NULL ; //存储解码器INFO列表

	BSTR   strGLSID;//

	//初始化COM环境
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//得到Image工厂接口对象
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

	//枚举编码器组件列表
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

	//释放内存
    CoTaskMemFree(Encodecs);

	//枚举解码器组件列表
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

	//释放内存
    CoTaskMemFree(Decodecs);

finish:
	//释放IImagingFactory接口对象
    if (pImagingFactory)
        pImagingFactory->Release();

	//释放程序占用的COM资源
    CoUninitialize();

}

/*
*函数介绍：将文件加载到内存流中
*入口参数：tszFilename：表示要打开的文件
*出口参数： ppStream : 表示内存流，将文件中的内容输出到此内存流中
*返回值：S_OK :表示成功，否则失败
*/
HRESULT CreateStreamOnFile(const TCHAR * tszFilename, IStream ** ppStream)
{
    HRESULT hrRet = S_FALSE;
    HGLOBAL hg = NULL;
    HANDLE hFile = NULL;
    DWORD dwSize, dwRead;
    BYTE* pbLocked = NULL;

    //打开文件
    hFile = CreateFile(tszFilename, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
    {
        goto error;
    }

	//得到文件大小
    dwSize = GetFileSize(hFile, NULL);
    if (0xffffffff == dwSize)
    {
        goto error;
    }

    //分配内存
    hg = GlobalAlloc(GMEM_MOVEABLE, dwSize);
    if (NULL == hg)
    {
        goto error;
    }

    //得到已经分配的内存指针
    pbLocked = (BYTE*) GlobalLock(hg);
    if (NULL == pbLocked)
    {
        goto error;
    }

    //读取文件内容到内存中
    if (!ReadFile(hFile, pbLocked, dwSize, &dwRead, NULL))
    {
        goto error;
    }

	//解锁已经分配全局内存，对应GlobalLock(hg)
    GlobalUnlock(hg);
    
    //创建Stream对象
    hrRet = CreateStreamOnHGlobal(hg, TRUE, ppStream);

	//关闭文件流
    CloseHandle(hFile);
    return hrRet;
error: //错误处理,并释放内存
    if (pbLocked)
        GlobalUnlock(hg);
    if (hg)
        GlobalFree(hg);
    if (hFile)
        CloseHandle(hFile);
    return hrRet;
}

/*
*函数介绍：根据编码器类型名称，得到指定的编码器CLSID
*入口参数：pImagingFactory: Image工厂接口对象
           wszMimeType : Image编码格式名称  
*出口参数：pclsid :编码器的CLSID
*返回值：TRUE : 成功; FALSE: 失败
*/
BOOL GetEnCodecCLSID(IImagingFactory* pImagingFactory,WCHAR * wszMimeType ,CLSID * pclsid )
{
    UINT uiCount;
    ImageCodecInfo * codecs;
    HRESULT hr;
    BOOL fRet = FALSE;

	//枚举系统已经安装的编码器
	hr = pImagingFactory->GetInstalledEncoders(&uiCount, &codecs);

	//查找制定编码器的CLSID
    for (UINT i = 0; i < uiCount; i++)
    {
        if (wszMimeType && !wcscmp(wszMimeType, codecs[i].MimeType))
        {
            *pclsid = codecs[i].Clsid;
            fRet = TRUE;
            break;
        }
    }
	//释放内存
    CoTaskMemFree(codecs);
	//
    return fRet;
}

//格式转换
void CImagingDemoDlg::OnBnClickedBtnChange()
{
		//用于将test.jpg转换成test.gif
		HRESULT hr;
		IImagingFactory * pImagingFactory = NULL ; //Image工厂接口对象
		IStream *pStream = NULL;	// 流接口对象
		IImageSink *pImageSink = NULL; //Image Sink接口对象
		IImageDecoder *pImageDecoder = NULL;   //解码器接口对象
		IImageEncoder *pImageEncoder = NULL;	//编码器接口对象
		CLSID clsidEncoder;  //编码器CLSID
		TCHAR *tszInFileName, *tszOutFileName, *tszMime;

		tszInFileName = L"\\test.bmp";  //指定待转换的图象文件
		tszOutFileName = L"\\test.jpg"; //指定转换后的图象文件
		tszMime = L"image/jpeg";	   //指定转换后，图象文件的格式

		//初始化COM环境
		if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
		{
       		TRACE(L"COINIT_MULTITHREADED ERROR");
			return;
		}

		//得到Image工厂接口对象
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


		//将文件内容加载到流中
        if (FAILED(hr = CreateStreamOnFile(tszInFileName, &pStream)))
        {
            goto finish;
        }

		//根据编码器类型名称得到编码器CLSID
        if (!GetEnCodecCLSID(pImagingFactory,tszMime, &clsidEncoder ))
        {
            goto finish;
        }

		//创建编码器接口，并关联到输出文件中
        if (FAILED(hr = pImagingFactory->CreateImageEncoderToFile(&clsidEncoder, tszOutFileName, &pImageEncoder)))
        {
            goto finish;
        }

		//创建解码器接口
        if (FAILED(hr = pImagingFactory->CreateImageDecoder(pStream, DecoderInitFlagBuiltIn1st, &pImageDecoder)))
        {
            goto finish;
        }

		//得到编码器接口的sink对象。此ImageSink接口作为一个槽或者管道来理解；
		//是用于负责pImageEncoder和pImageDecoder之间的传输
        if (FAILED(hr = pImageEncoder->GetEncodeSink(&pImageSink)))
        {
            goto finish;
        }

        //开始解码
        if (FAILED(hr = pImageDecoder->BeginDecode(pImageSink, NULL)))
        {
            goto finish;
        }

		//循环解码，直到结束
        for(;;)
        {
			//解码
            hr = pImageDecoder->Decode();
			//继续解码后面的部分
            if (E_PENDING == hr)
            {
                Sleep(500);
            }
			//失败
            else if (FAILED(hr))
            {
				//终止解码
                pImageDecoder->EndDecode(hr);
                goto finish;
            }
            else
            {
				//解码成功
                break;
            }
        }
		//结束解码
        pImageDecoder->EndDecode(hr);

		//释放pImageSink对象
        pImageSink->Release();
        pImageSink = NULL;

		//结束编码，此时就已经完成了文件格式的转换
        pImageEncoder->TerminateEncoder();

finish:
        
	//释放pStream对象
    if (pStream)
        pStream->Release();
        
	//释放pImageSink对象
    if (pImageSink)
        pImageSink->Release();

	//释放pImageDecoder对象
    if (pImageDecoder)
        pImageDecoder->Release();

	//释放pImageEncoder对象
    if (pImageEncoder)
        pImageEncoder->Release();

	//释放IImagingFactory接口对象
    if (pImagingFactory)
        pImagingFactory->Release();

	//释放程序占用的COM资源
    CoUninitialize();

}
