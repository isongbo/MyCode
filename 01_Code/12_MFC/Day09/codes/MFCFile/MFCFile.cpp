// MFCFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

void CFileTest()
{
  CFile file;
  try
  {
     //1 �򿪻����½�
	  file.Open("c:/MFCFile.txt",
		  CFile::modeCreate|CFile::modeReadWrite);
     //2 д����
	  char szWrite[]="Hello MFCFile!";
	  file.Write(szWrite,strlen(szWrite));
	  //��ȡ����ǰ�����Ƚ��ļ�ָ���ƶ����ļ���ͷ
	  file.SeekToBegin();
	  // �����ݲ��ڿ���̨��ӡ
	  char szRead[256]={0};
	  int nRead=file.Read(szRead,256);
      printf("�ļ����ݣ�%s\n",szRead);
	  printf("���ݳ���:%d\n",nRead);
	  //3 �ر��ļ�
	  file.Close();
  }
  catch(CFileException* e)
  {
     //�쳣����

  }
}
void FileStatusTest()
{
    //1 ��ȡָ���ļ��Ĵ���ʱ��
	CFileStatus status;
	CFile::GetStatus("c:/MFCFile.txt",status);
    //2 �޸��ļ��Ĵ���ʱ��
	CTimeSpan span(7,0,0,0);
    status.m_ctime-=span;
	//3 ����ָ���ļ��Ĵ���ʱ��
	CFile::SetStatus("c:/MFCFile.txt",status);

}
void FileFindTest(CString strPath)
{
	//1 ��ʼ����
	CFileFind find;
	BOOL bRet=find.FindFile(strPath+"/*.*");
	while(bRet)
	{
		//2 ������һ��
        bRet=find.FindNextFile();
		//3 ��ȡ���ж�
		CString strName=find.GetFileName();
		strPath=find.GetFilePath();
		if(find.IsDirectory()&&!find.IsDots())
		{
			printf("Ŀ¼��%s\n",strPath);
			FileFindTest(strPath);
		}
		else
		{
	        printf("�ļ���%s\n",strPath);
		}
	}
	// 4 ��������
	find.Close();
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//�ļ���д����
    //CFileTest();
    //�޸��ļ��Ĵ���ʱ��
	//FileStatusTest();

	FileFindTest("F:/MFC");
	return 0;
}


