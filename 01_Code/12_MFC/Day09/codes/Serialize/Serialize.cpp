// Serialize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Serialize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
//写数据(存储数据)
void Store()
{
    
	CFile file;
	file.Open("c:/serial.bin",
		CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file,CArchive::store);
	ar<<100<<12.25<<'A';
	ar.Close();
	file.Close();
}
// 读数据(加载数据)
void Load()
{
	CFile file;
	file.Open("c:/serial.bin",CFile::modeRead);
	CArchive ar(&file,CArchive::load);
	int nValue=0;
	double dValue=0.0;
	char cValue;
	ar>>nValue>>dValue>>cValue;
	ar.Close();
	file.Close();
	//在控制条打印
	printf("nValue=%d\n",nValue);
	printf("dValue=%f\n",dValue);
	printf("cValue=%c\n",cValue);

}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	Store();
	Load();

	return 0;
}


