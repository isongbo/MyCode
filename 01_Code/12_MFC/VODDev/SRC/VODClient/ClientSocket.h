 // ClientSocket.h: interface for the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_)
#define AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef struct _tagVODHeader{
    DWORD dwVer;
    DWORD dwCmd;
    DWORD dwLen;
}VODHEADER,* LPVODHEADER;

#define VODNETCMD_LOGIN 0x00000001

typedef struct _tagVODLogin{
    CHAR szUserName[128];
    CHAR szPassword[128];
}VODLOGIN,* LPVODLOGIN;

#define VODNETCMD_LOGIN_RET 0x80000001

typedef struct _tagVODLoginRet{
    DWORD dwSuccess;
}VODLOGINRET,* LPVODLOGINRET;

#define  VODNETCMD_TYPES 0x00000002

#define  VODNETCMD_TYPES_RET 0x80000002


#define VODNETCMD_GETVIDES 0x00000003
typedef struct _tagGetVideos
{
   DWORD typdID;
}GETVIDEOS,*LPGETVIDEOS; 

#define VODNETCMD_GETVIDEOS_RET 0x80000003



#define VODNETCMD_MEDIADATA 0x00000006
typedef struct _tagMediaData{
    DWORD videoID;//发送影片ID
}MEDIADATA,* LPMEDIADATA;
#define VODNETCMD_MEDIADATA_RET 0x80000006
typedef struct _tagMediaDataRet{
    CHAR szFileName[128];//返回影片的信息
    DWORD dwFileLen;//文件长度
}MEDIADATARET,* LPMEDIADATARET;



class CClientSocket  
{
public:
	CClientSocket();
	virtual ~CClientSocket();
public:
	//客户端初始化，连接服务器
	BOOL Initialize();
	//1 登录
    BOOL Login(LPCSTR pszName,LPCSTR pszPwd);
	//2 获取所有视频类型信息
	BOOL GetAllVideoTypes(CString & types);
	//3 获取指定类型的所有视频名称
	BOOL GetVideosByTypeID(DWORD typeID,CString & videos);
	//4 获取指定视频ID的视频文件（下载视频文件）
    BOOL GetMediaData(DWORD videoID,LPCSTR pszFilePath,CString & strFullPath);
    
	
	//原始的数据传输函数
    BOOL SendData(DWORD dwCmdID,LPVOID pData,UINT nLen );
	BOOL RecvData(LPVOID  pData,UINT nLen);
	BOOL SendRaw(LPVOID  pData,UINT nLen);
public:
    SOCKET m_hClientSock;
};

#endif // !defined(AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_)
