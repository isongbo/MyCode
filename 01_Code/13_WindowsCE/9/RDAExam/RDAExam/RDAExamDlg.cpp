// RDAExamDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RDAExam.h"
#include "RDAExamDlg.h"

#include "DlgSubmit.h"

#include "DlgPull.h"
#include "DlgPush.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CRDAExamDlg �Ի���

CRDAExamDlg::CRDAExamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRDAExamDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRDAExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRDAExamDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_SUBMIT, &CRDAExamDlg::OnBnClickedBtnSubmit)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_PULL, &CRDAExamDlg::OnBnClickedBtnPull)
	ON_BN_CLICKED(IDC_BTN_PUSH, &CRDAExamDlg::OnBnClickedBtnPush)
END_MESSAGE_MAP()


// CRDAExamDlg ��Ϣ�������

BOOL CRDAExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	//��ʼ��COM����
	CoInitializeEx(NULL,COINIT_MULTITHREADED);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//�Ի��������¼�
void CRDAExamDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//ж��COM����
	CoUninitialize();
}


//��ʾԶ�����ݷ���ʱ�Ĵ���
void    CRDAExamDlg::ShowErrors(ISSCEErrors* pISSCEErrors)
{
	HRESULT       hr;
	LONG          cbBuf;
	LONG          i;
	LONG          lErrorCount;
	LONG          lErrorIndex;
	LONG          lParamCount;
	LONG          lParamIndex;
	VARIANT       var;
	VARIANT       varParam;
	WCHAR         wszBuff[4096];
	WCHAR*        pwszBuffPos   = &wszBuff[0];
	BSTR          bstr;
	ISSCEError*   pISSCEError   = NULL;
	ISSCEParams*  pISSCEParams  = NULL;
	ISSCEParam*   pISSCEParam   = NULL;
	BOOL          fSuccess      = FALSE;
	
	//��ʼ������
	VariantInit(&var);
	VariantInit(&varParam);
	
	//ͨ��IISSCEErrors�ӿڵõ��������������
	if(FAILED(hr = pISSCEErrors->get_Count(&lErrorCount))) 
		goto Exit;
	if (lErrorCount <= 0)
	{
		::MessageBox(NULL, L"û�д�����Ϣ",L"��ʾ����", MB_OK);
		fSuccess = TRUE;
		goto Exit;
	}
	
	//�õ����Ի�����ʾÿһ�������Ĵ���
	for (lErrorIndex = 0; lErrorIndex < lErrorCount; lErrorIndex++)
    {
		cbBuf = swprintf(pwszBuffPos, L"ERROR  %d of %d\r\n",
			lErrorIndex+1, lErrorCount);
		pwszBuffPos += cbBuf;
		
		//�õ������¼
		var.vt = VT_I4;
		var.lVal = lErrorIndex;
		if(FAILED(hr = pISSCEErrors->get_Item(var, &pISSCEError))) goto Exit;
		
		//�õ�������ϸ��Ϣ
		if (FAILED(hr = pISSCEError->get_Description(&bstr))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"DESCRIPTION: '%s'\r\n", bstr);
		pwszBuffPos += cbBuf;
		SysFreeString(bstr);
		
		//������Ϣ���
		if (FAILED(hr = pISSCEError->get_Number(&i))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"NUMBER: %8.8X\r\n", i);
		pwszBuffPos += cbBuf;
		
		//���ش���
		if (FAILED(hr = pISSCEError->get_NativeError(&i))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"NATIVE_ERROR: %d\r\n", i);
		pwszBuffPos += cbBuf;
		
		//�õ�����Դ
		if (FAILED(hr = pISSCEError->get_Source(&bstr))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"SOURCE: '%s'\r\n", bstr);
		pwszBuffPos += cbBuf;
		SysFreeString(bstr);
		
		//�õ����������Ϣ
		if (FAILED(hr = pISSCEError->get_Params(&pISSCEParams))) goto Exit;
		
		//�õ���������ĸ���
		if (FAILED(hr = pISSCEParams->get_Count(&lParamCount))) goto Exit;
		
		//��ʾÿһ������
		for (lParamIndex = 0; lParamIndex < lParamCount; lParamIndex++)
        {
			
			//�õ������������
			var.vt = VT_I4;
			var.lVal = lParamIndex;
			if (FAILED(hr = pISSCEParams->get_Item(var, &pISSCEParam))) goto Exit;
			
			//�õ�����ʾ�������ֵ
			if (FAILED(hr = pISSCEParam->get_Param(&varParam))) goto Exit;
			if (VT_I4 == varParam.vt || VT_UI4 == varParam.vt)
            {
				cbBuf = swprintf(pwszBuffPos, L"P%d: %d\r\n", lParamIndex,
					(LONG) varParam.lVal);
            }
			else if (VT_I2 == varParam.vt || VT_UI2 == varParam.vt)
            {
				cbBuf = swprintf(pwszBuffPos, L"P%d: %d\r\n", lParamIndex,
					(LONG) varParam.iVal);
            }
			else if (VT_BSTR == varParam.vt)
            {
				cbBuf = swprintf(pwszBuffPos, L"P%d: '%s'\r\n", lParamIndex, 
					varParam.bstrVal);
            }
			pwszBuffPos += cbBuf;
			
			//��ղ�������
			VariantClear(&varParam);
			
			//�ͷŲ�������
			pISSCEParam->Release();
			pISSCEParam = NULL;
        }
		cbBuf = swprintf(pwszBuffPos, L"\r\n");
		pwszBuffPos += cbBuf;
		
    }
	
	//�õ�������ʾ������Ϣ
	::MessageBox(NULL, wszBuff,L"Error", MB_OK);
	fSuccess = TRUE;
	
Exit:
	// �ͷŴ����������
	if (pISSCEParam)
    {
		pISSCEParam->Release();
		pISSCEParam = NULL;
    }
	
	//�ͷŴ������������
	if (pISSCEParams)
    {
		pISSCEParams->Release();
		pISSCEParams = NULL;
    }
	
	//�ͷŴ������
	if (pISSCEError)
    {
		pISSCEError->Release();
		pISSCEError = NULL;
    }
	
	//�����ȡ������Ϣʧ��
	if (!fSuccess)
    {
		::MessageBox(NULL, L"�õ�������Ϣʧ��!",L"��ʾ����", MB_OK);
    }
	return;
}



//��ִ��Զ��SQL��䴰��
void CRDAExamDlg::OnBnClickedBtnSubmit() 
{
	ISSCERDA*			pCERDA = NULL;
	BSTR bStr = NULL;
	BSTR bConnectStr = NULL;
	BSTR bQueryStr = NULL;
	SYSTEMTIME			systemtime;					// ϵͳʱ��
	double				timeTotal;					// �ܹ����ĵ�ʱ��
	__int64				timeStart = 0;				// ��ʼ����ʱ��ʱ��
	__int64				timeStop;					// ��������ʱ��ʱ��
	WCHAR	wszBuffer[512];


	CDlgSubmit dlgSubmit;
	if (dlgSubmit.DoModal())
	{
		//�õ�pCERDA�ӿ�
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1������Internet URL
		bStr = SysAllocString(dlgSubmit.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2������Internet userName
		bStr = SysAllocString(dlgSubmit.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3������Internet password
		bStr = SysAllocString(dlgSubmit.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		
		//4�����÷��������Ӵ�
		bConnectStr = SysAllocString(dlgSubmit.m_connectStr);
		//5������ִ�е�Զ��SQL���
		bQueryStr = SysAllocString(dlgSubmit.m_queryStr);

		//��¼ִ��SQL���ǰ��ʱ��
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //ִ��Զ��SQL���
		hr = pCERDA->SubmitSQL(bQueryStr,bConnectStr);

		SysFreeString(bQueryStr);
		SysFreeString(bConnectStr);	
		if (SUCCEEDED(hr))
		{
			//��¼ִ��SQL�����ʱ��
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //��¼ִ��SQL����ܹ����ĵ�ʱ��
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("ִ��Զ��SQL���ɹ�\r\n\r\�ܹ����� = %8.3f��"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//��ʾִ��Զ��SQL������
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//�ͷ�Զ�̷��ʽӿ�
		pCERDA->Release();
	}
}

//��Զ�̷�������ȡ����
void CRDAExamDlg::OnBnClickedBtnPull()
{
	//
	ISSCERDA*			pCERDA = NULL;
	BSTR bStr = NULL;
	BSTR bConnectStr = NULL;
	BSTR bQueryStr = NULL;
	BSTR bLocalConnectStr = NULL;
	BSTR bLocalTableName = NULL;
	BSTR bErrorTableName  = NULL;
	RDA_TRACKOPTION trackOption = TRACKINGOFF;

	SYSTEMTIME			systemtime;					// ϵͳʱ��
	double				timeTotal;					// �ܹ����ĵ�ʱ��
	__int64				timeStart = 0;				// ��ʼ����ʱ��ʱ��
	__int64				timeStop;					// ��������ʱ��ʱ��
	WCHAR	wszBuffer[512];

   	CDlgPull dlgPull;
	if (dlgPull.DoModal())
	{
		//�õ�pCERDA�ӿ�
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1������Internet URL
		bStr = SysAllocString(dlgPull.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2������Internet userName
		bStr = SysAllocString(dlgPull.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3������Internet password
		bStr = SysAllocString(dlgPull.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		
		//4���õ���������
		if (dlgPull.m_tracking == L"TRACKINGON")
		{
			trackOption = TRACKINGON;
		}else if (dlgPull.m_tracking == L"TRACKINGOFF")
		{
			trackOption = TRACKINGOFF;
		}else if (dlgPull.m_tracking == L"TRACKINGON_INDEXES")
		{
			trackOption = TRACKINGON_INDEXES;
		}else if(dlgPull.m_tracking == L"TRACKINGOFF_INDEXES")
		{
			trackOption = TRACKINGOFF_INDEXES;
		}else
		{
			trackOption = TRACKINGOFF;
		}
		
		//5�����ô������
		bErrorTableName = SysAllocString(dlgPull.m_errorTableName);

		//6�����÷��������Ӵ�
		bConnectStr = SysAllocString(dlgPull.m_connectStr);

		//7�����ñ������ݿ����Ӵ�
		bLocalConnectStr = SysAllocString(dlgPull.m_localConnectStr);
		pCERDA->put_LocalConnectionString(bLocalConnectStr);
		SysFreeString(bStr);

		//8�����ñ��ر���
		bLocalTableName = SysAllocString(dlgPull.m_localTableName);

		//9�����ò�ѯ��SQL���
		bQueryStr = SysAllocString(dlgPull.m_queryStr);
		
		//��¼��ȡ����������ǰ��ʱ��
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //��ȡ����������
		hr = pCERDA->Pull(bLocalTableName, 
		 			         bQueryStr, 
	   						 bConnectStr, 
		 					 trackOption,
							 bErrorTableName);

		SysFreeString(bLocalTableName);
		SysFreeString(bQueryStr);
		SysFreeString(bConnectStr);
		SysFreeString(bErrorTableName);

		if (SUCCEEDED(hr))
		{
			//��¼��ȡ���������ݺ��ʱ��
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //��¼��ȡ���������ݵ���ʱ��
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("�ӷ�������ȡ���ݳɹ�\r\n\r\�ܹ����� = %8.3f��"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//��ʾ��ȡ���������ݴ���
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//�ͷ�Զ�̷��ʽӿ�
		pCERDA->Release();
	}
}

//��������ύ����
void CRDAExamDlg::OnBnClickedBtnPush()
{
	ISSCERDA*			pCERDA = NULL;
	BSTR bStr = NULL;
	BSTR bConnectStr = NULL;
	BSTR bLocalConnectStr = NULL;
	BSTR bLocalTableName = NULL;

	SYSTEMTIME			systemtime;					// ϵͳʱ��
	double				timeTotal;					// �ܹ����ĵ�ʱ��
	__int64				timeStart = 0;				// ��ʼ����ʱ��ʱ��
	__int64				timeStop;					// ��������ʱ��ʱ��
	WCHAR	wszBuffer[512];

   	CDlgPush dlgPush;
	if (dlgPush.DoModal())
	{
		//�õ�pCERDA�ӿ�
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1������Internet URL
		bStr = SysAllocString(dlgPush.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2������Internet userName
		bStr = SysAllocString(dlgPush.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3������Internet password
		bStr = SysAllocString(dlgPush.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		

		//4�����÷��������Ӵ�
		bConnectStr = SysAllocString(dlgPush.m_connectStr);

		//5�����ñ������ݿ����Ӵ�
		bLocalConnectStr = SysAllocString(dlgPush.m_localConnectStr);
		pCERDA->put_LocalConnectionString(bLocalConnectStr);
		SysFreeString(bStr);

		//6�����ñ��ر���
		bLocalTableName = SysAllocString(dlgPush.m_localTableName);

		
		//��¼��������ύ����ǰ��ʱ��
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //��������ύ����
		hr = pCERDA->Push(bLocalTableName,bConnectStr, BATCHINGOFF);

		SysFreeString(bLocalTableName);
		SysFreeString(bConnectStr);

		if (SUCCEEDED(hr))
		{
			//��¼��������ύ���ݺ��ʱ��
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //��¼��������ύ�����ܵ�ʱ��
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("��������ύ���ݳɹ�\r\n\r\�ܹ����� = %8.3f��"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//��ʾ��������ύ����ʧ����Ϣ
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//�ͷ�Զ�̷��ʽӿ�
		pCERDA->Release();
	}

}
