// StudentInputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EDBUse.h"
#include "StudentInputDlg.h"


// CStudentInputDlg �Ի���

IMPLEMENT_DYNAMIC(CStudentInputDlg, CDialog)

//���캯��
CStudentInputDlg::CStudentInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentInputDlg::IDD, pParent)
	, m_no(_T(""))
	, m_name(_T(""))
	, m_birthday(0)
	, m_stature(0)
{
	//��ʼ��m_blImage
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


// CStudentInputDlg ��Ϣ�������

//CStudentInputDlg��ʼ���¼�
BOOL CStudentInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//���ѧ����Ƭ���ݲ�Ϊ�գ���ʾ��Ƭ
	if (m_blImage.dwCount > 0)
	{
		m_Image.LoadImageFromBuffer(m_blImage.dwCount,m_blImage.lpb);
	}

	return TRUE;
}



//���ļ����ݶ�ȡ���ڴ滺������
BOOL CStudentInputDlg::ReadFileToBlob(LPCTSTR strFileName, /*in �ļ���*/
		CEBLOB *pBlob /*out ����Ļ�����*/)
{
	
    HANDLE hFile = NULL; //�ļ����
    DWORD dwSize = 0, dwRead = 0;
	DWORD dwError = 0;

    //���ļ�
    hFile = CreateFile(strFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
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

	//�ͷ��ڴ�
	if (pBlob->lpb != NULL)
	{
		delete[] pBlob->lpb;
		pBlob->lpb = NULL;
		pBlob->dwCount = 0;

	}

	//�����ڴ�
	pBlob->lpb = new BYTE[dwSize];
	ZeroMemory(pBlob->lpb,dwSize);
	pBlob->dwCount = dwSize;
	
    //��ȡ�ļ����ݵ��ڴ���
	if (!ReadFile(hFile, pBlob->lpb, dwSize, &dwRead, NULL))
    {
        goto error;
    }

	ASSERT(dwSize == dwRead);

	//�ر��ļ�
	CloseHandle(hFile);

	return TRUE;
error:
	if (hFile != NULL)
	{
		//�ر��ļ���
		CloseHandle(hFile);
	}

	//�ͷ��ڴ�
	if (pBlob->lpb != NULL)
	{
		delete[] pBlob->lpb;
		pBlob->lpb = NULL;
		pBlob->dwCount = 0;
	}
	return FALSE;
}

//������Ƭ��
void CStudentInputDlg::OnStnClickedImgPicture()
{
	CString strFileName = L"";
	CFileDialog *pDlgInput;
	//ָ���򿪵�ͼƬ��ʽ
	TCHAR szFilter[] = L"Bmp Files (*.bmp)|*.bmp|Jpeg Files(*.jpg;*.jpeg)|*.jpg;*.jpeg|Gif Files (*.gif)|*.gif||";

	//���ļ�ѡ��Ի���
	pDlgInput = new CFileDialog(TRUE,L"*.jpg",NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,this,0);
	if (pDlgInput->DoModal() == IDOK)
	{
		//�õ��ļ���
		strFileName = pDlgInput->GetPathName();
		//���ļ����ص��ڴ���
		ReadFileToBlob(strFileName,&m_blImage);
		//��ʾͼƬ
		m_Image.LoadImageFromFile(strFileName);
	}
}

//ȷ����ť�����¼�
void CStudentInputDlg::OnBnClickedBtnOk()
{
	OnOK();
}

//ȡ����ť�����¼�
void CStudentInputDlg::OnBnClickedBtnCancel()
{
	OnCancel();
}

