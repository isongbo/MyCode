// RDAExamDlg.cpp : 实现文件
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

// CRDAExamDlg 对话框

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


// CRDAExamDlg 消息处理程序

BOOL CRDAExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	//初始化COM环境
	CoInitializeEx(NULL,COINIT_MULTITHREADED);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//对话框销毁事件
void CRDAExamDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//卸载COM环境
	CoUninitialize();
}


//显示远程数据访问时的错误
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
	
	//初始化变量
	VariantInit(&var);
	VariantInit(&varParam);
	
	//通过IISSCEErrors接口得到发生错误的数量
	if(FAILED(hr = pISSCEErrors->get_Count(&lErrorCount))) 
		goto Exit;
	if (lErrorCount <= 0)
	{
		::MessageBox(NULL, L"没有错误信息",L"显示错误", MB_OK);
		fSuccess = TRUE;
		goto Exit;
	}
	
	//用弹出对话框显示每一条发生的错误
	for (lErrorIndex = 0; lErrorIndex < lErrorCount; lErrorIndex++)
    {
		cbBuf = swprintf(pwszBuffPos, L"ERROR  %d of %d\r\n",
			lErrorIndex+1, lErrorCount);
		pwszBuffPos += cbBuf;
		
		//得到错误记录
		var.vt = VT_I4;
		var.lVal = lErrorIndex;
		if(FAILED(hr = pISSCEErrors->get_Item(var, &pISSCEError))) goto Exit;
		
		//得到错误详细信息
		if (FAILED(hr = pISSCEError->get_Description(&bstr))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"DESCRIPTION: '%s'\r\n", bstr);
		pwszBuffPos += cbBuf;
		SysFreeString(bstr);
		
		//错误信息编号
		if (FAILED(hr = pISSCEError->get_Number(&i))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"NUMBER: %8.8X\r\n", i);
		pwszBuffPos += cbBuf;
		
		//本地错误
		if (FAILED(hr = pISSCEError->get_NativeError(&i))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"NATIVE_ERROR: %d\r\n", i);
		pwszBuffPos += cbBuf;
		
		//得到错误源
		if (FAILED(hr = pISSCEError->get_Source(&bstr))) goto Exit;
		cbBuf = swprintf(pwszBuffPos, L"SOURCE: '%s'\r\n", bstr);
		pwszBuffPos += cbBuf;
		SysFreeString(bstr);
		
		//得到错误参数信息
		if (FAILED(hr = pISSCEError->get_Params(&pISSCEParams))) goto Exit;
		
		//得到错误参数的个数
		if (FAILED(hr = pISSCEParams->get_Count(&lParamCount))) goto Exit;
		
		//显示每一个参数
		for (lParamIndex = 0; lParamIndex < lParamCount; lParamIndex++)
        {
			
			//得到错误参数对象
			var.vt = VT_I4;
			var.lVal = lParamIndex;
			if (FAILED(hr = pISSCEParams->get_Item(var, &pISSCEParam))) goto Exit;
			
			//得到并显示错误参数值
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
			
			//清空参数变量
			VariantClear(&varParam);
			
			//释放参数对象
			pISSCEParam->Release();
			pISSCEParam = NULL;
        }
		cbBuf = swprintf(pwszBuffPos, L"\r\n");
		pwszBuffPos += cbBuf;
		
    }
	
	//用弹出框显示错误信息
	::MessageBox(NULL, wszBuff,L"Error", MB_OK);
	fSuccess = TRUE;
	
Exit:
	// 释放错误参数对象
	if (pISSCEParam)
    {
		pISSCEParam->Release();
		pISSCEParam = NULL;
    }
	
	//释放错误参数集对象
	if (pISSCEParams)
    {
		pISSCEParams->Release();
		pISSCEParams = NULL;
    }
	
	//释放错误对象
	if (pISSCEError)
    {
		pISSCEError->Release();
		pISSCEError = NULL;
    }
	
	//如果获取错误信息失败
	if (!fSuccess)
    {
		::MessageBox(NULL, L"得到错误信息失败!",L"显示错误", MB_OK);
    }
	return;
}



//打开执行远程SQL语句窗口
void CRDAExamDlg::OnBnClickedBtnSubmit() 
{
	ISSCERDA*			pCERDA = NULL;
	BSTR bStr = NULL;
	BSTR bConnectStr = NULL;
	BSTR bQueryStr = NULL;
	SYSTEMTIME			systemtime;					// 系统时间
	double				timeTotal;					// 总共消耗的时间
	__int64				timeStart = 0;				// 开始操作时的时间
	__int64				timeStop;					// 结束操作时的时间
	WCHAR	wszBuffer[512];


	CDlgSubmit dlgSubmit;
	if (dlgSubmit.DoModal())
	{
		//得到pCERDA接口
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1、设置Internet URL
		bStr = SysAllocString(dlgSubmit.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2、设置Internet userName
		bStr = SysAllocString(dlgSubmit.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3、设置Internet password
		bStr = SysAllocString(dlgSubmit.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		
		//4、设置服务器连接串
		bConnectStr = SysAllocString(dlgSubmit.m_connectStr);
		//5、设置执行的远程SQL语句
		bQueryStr = SysAllocString(dlgSubmit.m_queryStr);

		//记录执行SQL语句前的时间
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //执行远程SQL语句
		hr = pCERDA->SubmitSQL(bQueryStr,bConnectStr);

		SysFreeString(bQueryStr);
		SysFreeString(bConnectStr);	
		if (SUCCEEDED(hr))
		{
			//记录执行SQL语句后的时间
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //记录执行SQL语句总共消耗的时间
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("执行远程SQL语句成功\r\n\r\总共消耗 = %8.3f秒"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//显示执行远程SQL语句错误
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//释放远程访问接口
		pCERDA->Release();
	}
}

//从远程服务器获取数据
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

	SYSTEMTIME			systemtime;					// 系统时间
	double				timeTotal;					// 总共消耗的时间
	__int64				timeStart = 0;				// 开始操作时的时间
	__int64				timeStop;					// 结束操作时的时间
	WCHAR	wszBuffer[512];

   	CDlgPull dlgPull;
	if (dlgPull.DoModal())
	{
		//得到pCERDA接口
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1、设置Internet URL
		bStr = SysAllocString(dlgPull.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2、设置Internet userName
		bStr = SysAllocString(dlgPull.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3、设置Internet password
		bStr = SysAllocString(dlgPull.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		
		//4、得到跟踪类型
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
		
		//5、设置错误表名
		bErrorTableName = SysAllocString(dlgPull.m_errorTableName);

		//6、设置服务器连接串
		bConnectStr = SysAllocString(dlgPull.m_connectStr);

		//7、设置本地数据库连接串
		bLocalConnectStr = SysAllocString(dlgPull.m_localConnectStr);
		pCERDA->put_LocalConnectionString(bLocalConnectStr);
		SysFreeString(bStr);

		//8、设置本地表名
		bLocalTableName = SysAllocString(dlgPull.m_localTableName);

		//9、设置查询的SQL语句
		bQueryStr = SysAllocString(dlgPull.m_queryStr);
		
		//记录获取服务器数据前的时间
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //获取服务器数据
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
			//记录获取服务器数据后的时间
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //记录获取服务器数据的总时间
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("从服务器获取数据成功\r\n\r\总共消耗 = %8.3f秒"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//显示获取服务器数据错误
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//释放远程访问接口
		pCERDA->Release();
	}
}

//向服务器提交数据
void CRDAExamDlg::OnBnClickedBtnPush()
{
	ISSCERDA*			pCERDA = NULL;
	BSTR bStr = NULL;
	BSTR bConnectStr = NULL;
	BSTR bLocalConnectStr = NULL;
	BSTR bLocalTableName = NULL;

	SYSTEMTIME			systemtime;					// 系统时间
	double				timeTotal;					// 总共消耗的时间
	__int64				timeStart = 0;				// 开始操作时的时间
	__int64				timeStop;					// 结束操作时的时间
	WCHAR	wszBuffer[512];

   	CDlgPush dlgPush;
	if (dlgPush.DoModal())
	{
		//得到pCERDA接口
		HRESULT hr = CoCreateInstance(CLSID_RemoteDataAccess, NULL, CLSCTX_INPROC_SERVER, IID_ISSCERDA, (LPVOID *)&pCERDA);
		ASSERT(hr == S_OK);
		ASSERT(pCERDA != NULL);
		//1、设置Internet URL
		bStr = SysAllocString(dlgPush.m_internetURL);
		pCERDA->put_InternetURL(bStr);
		SysFreeString(bStr);

		//2、设置Internet userName
		bStr = SysAllocString(dlgPush.m_internetUsername);
		pCERDA->put_InternetLogin(bStr);
		SysFreeString(bStr);

		//3、设置Internet password
		bStr = SysAllocString(dlgPush.m_internetPassword);
		pCERDA->put_InternetPassword(bStr);
		SysFreeString(bStr);
		

		//4、设置服务器连接串
		bConnectStr = SysAllocString(dlgPush.m_connectStr);

		//5、设置本地数据库连接串
		bLocalConnectStr = SysAllocString(dlgPush.m_localConnectStr);
		pCERDA->put_LocalConnectionString(bLocalConnectStr);
		SysFreeString(bStr);

		//6、设置本地表名
		bLocalTableName = SysAllocString(dlgPush.m_localTableName);

		
		//记录向服务器提交数据前的时间
		GetLocalTime(&systemtime);
		SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStart);

        //向服务器提交数据
		hr = pCERDA->Push(bLocalTableName,bConnectStr, BATCHINGOFF);

		SysFreeString(bLocalTableName);
		SysFreeString(bConnectStr);

		if (SUCCEEDED(hr))
		{
			//记录向服务器提交数据后的时间
			GetLocalTime(&systemtime);
			SystemTimeToFileTime(&systemtime, (FILETIME*)&timeStop);
            //记录向服务器提交数据总的时间
			timeTotal = ((double)(timeStop - timeStart) / 10000000);
			swprintf(wszBuffer, _T("向服务器提交数据成功\r\n\r\总共消耗 = %8.3f秒"), timeTotal); 
			AfxMessageBox(wszBuffer);
		}
		else
		{	
			//显示向服务器提交数据失败信息
			ISSCEErrors  *pISSCEErrors = NULL;
			if(SUCCEEDED(hr = pCERDA->get_ErrorRecords(&pISSCEErrors)))
			{
				ShowErrors(pISSCEErrors);
				pISSCEErrors->Release();
			}
		}
		//释放远程访问接口
		pCERDA->Release();
	}

}
