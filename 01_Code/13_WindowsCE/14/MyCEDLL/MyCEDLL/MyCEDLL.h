// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MYCEDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MYCEDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MYCEDLL_EXPORTS
#define MYCEDLL_API __declspec(dllexport)
#else
#define MYCEDLL_API __declspec(dllimport)
#endif

// �����Ǵ� MyCEDLL.dll ������
class MYCEDLL_API CMyCEDLL {
public:
	CMyCEDLL(void);
	// TODO: �ڴ�������ķ�����
};

extern MYCEDLL_API int nMyCEDLL;

MYCEDLL_API int fnMyCEDLL(void);

extern "C" MYCEDLL_API void TestDll(void);