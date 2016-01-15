// StudentInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EDBUse.h"
#include "StudentInputDlg.h"


// CStudentInputDlg 对话框

IMPLEMENT_DYNAMIC(CStudentInputDlg, CDialog)

//构造函数
CStudentInputDlg::CStudentInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentInputDlg::IDD, pParent)
	, m_no(_T(""))
	, m_name(_T(""))
	, m_birthday(0)
	, m_stature(0)
{
	//初始化m_blImage
	ZeroMemory(&m_blImage,sizeof(m_blImage));
}

CStudentInputDlg::~CStudentInputDlg()
{
}

void CStudentInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_NO, m_no);
	DDX_Text(pDX, IDC_EDT_NAME, m_name);
	DDX_DateTimeCtrl(pDX, IDC_DT_BIRTHDAY, m_birthday);
	DDX_Text(pDX, IDC_DT_STATURE, m_stature);
	DDX_Control(pDX, IDC_IMG_PICTURE, m_Image);
}


BEGIN_MESSAGE_MAP(CStudentInputDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CStudentInputDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CStudentInputDlg::OnBnClickedBtnCancel)
	ON_STN_CLICKED(IDC_IMG_PICTURE, &CStudentInputDlg::OnStnClickedImgPicture)
END_MESSAGE_MAP()


// CStudentInputDlg 消息处理程序

//CStudentInputDlg初始化事件
BOOL CStudentInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//如果学生照片数据不为空，显示照片
	if (m_blImage.dwCount > 0)
	{
		m_Image.LoadImageFromBuffer(m_blImage.dwCount,m_blImage.lpb);
	}

	return TRUE;
}



//将文件内容读取到内存缓冲区中
BOOL CStudentInputDlg::ReadFileToBlob(LPCTSTR strFileName, /*in 文件名*/
		CEBLOB *pBlob /*out 输出的缓冲区*/)
{
	
    HANDLE hFile = NULL; //文件句柄
    DWORD dwSize = 0, dwRead = 0;
	DWORD dwError = 0;

    //打开文件
    hFile = CreateFile(strFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
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

	//释放内存
	if (pBlob->lpb != NULL)
	{
		delete[] pBlob->lpb;
		pBlob->lpb = NULL;
		pBlob->dwCount = 0;

	}

	//分配内存
	pBlob->lpb = new BYTE[dwSize];
	ZeroMemory(pBlob->lpb,dwSize);
	pBlob->dwCount = dwSize;
	
    //读取文件内容到内存中
	if (!ReadFile(hFile, pBlob->lpb, dwSize, &dwRead, NULL))
    {
        goto error;
    }

	ASSERT(dwSize == dwRead);

	//关闭文件
	CloseHandle(hFile);

	return TRUE;
error:
	if (hFile != NULL)
	{
		//关闭文件流
		CloseHandle(hFile);
	}

	//释放内存
	if (pBlob->lpb != NULL)
	{
		delete[] pBlob->lpb;
		pBlob->lpb = NULL;
		pBlob->dwCount = 0;
	}
	return FALSE;
}

//单击照片框
void CStudentInputDlg::OnStnClickedImgPicture()
{
	CString strFileName = L"";
	CFileDialog *pDlgInput;
	//指定打开的图片格式
	TCHAR szFilter[] = L"Bmp Files (*.bmp)|*.bmp|Jpeg Files(*.jpg;*.jpeg)|*.jpg;*.jpeg|Gif Files (*.gif)|*.gif||";

	//打开文件选择对话框
	pDlgInput = new CFileDialog(TRUE,L"*.jpg",NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,this,0);
	if (pDlgInput->DoModal() == IDOK)
	{
		//得到文件名
		strFileName = pDlgInput->GetPathName();
		//将文件记载到内存中
		ReadFileToBlob(strFileName,&m_blImage);
		//显示图片
		m_Image.LoadImageFromFile(strFileName);
	}
}

//确定按钮单击事件
void CStudentInputDlg::OnBnClickedBtnOk()
{
	OnOK();
}

//取消按钮单击事件
void CStudentInputDlg::OnBnClickedBtnCancel()
{
	OnCancel();
}

