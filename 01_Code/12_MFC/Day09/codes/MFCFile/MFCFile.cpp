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
     //1 打开或者新建
	  file.Open("c:/MFCFile.txt",
		  CFile::modeCreate|CFile::modeReadWrite);
     //2 写数据
	  char szWrite[]="Hello MFCFile!";
	  file.Write(szWrite,strlen(szWrite));
	  //读取数据前，首先将文件指针移动到文件开头
	  file.SeekToBegin();
	  // 读数据并在控制台打印
	  char szRead[256]={0};
	  int nRead=file.Read(szRead,256);
      printf("文件内容：%s\n",szRead);
	  printf("内容长度:%d\n",nRead);
	  //3 关闭文件
	  file.Close();
  }
  catch(CFileException* e)
  {
     //异常处理

  }
}
void FileStatusTest()
{
    //1 获取指定文件的创建时间
	CFileStatus status;
	CFile::GetStatus("c:/MFCFile.txt",status);
    //2 修改文件的创建时间
	CTimeSpan span(7,0,0,0);
    status.m_ctime-=span;
	//3 设置指定文件的创建时间
	CFile::SetStatus("c:/MFCFile.txt",status);

}
void FileFindTest(CString strPath)
{
	//1 开始查找
	CFileFind find;
	BOOL bRet=find.FindFile(strPath+"/*.*");
	while(bRet)
	{
		//2 查找下一个
        bRet=find.FindNextFile();
		//3 获取和判断
		CString strName=find.GetFileName();
		strPath=find.GetFilePath();
		if(find.IsDirectory()&&!find.IsDots())
		{
			printf("目录：%s\n",strPath);
			FileFindTest(strPath);
		}
		else
		{
	        printf("文件：%s\n",strPath);
		}
	}
	// 4 结束查找
	find.Close();
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//文件读写操作
    //CFileTest();
    //修改文件的创建时间
	//FileStatusTest();

	FileFindTest("F:/MFC");
	return 0;
}


