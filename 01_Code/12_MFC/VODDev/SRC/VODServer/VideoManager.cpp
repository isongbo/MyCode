// VideoManager.cpp: implementation of the CVideoManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vodserver.h"
#include "VideoManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVideoManager::CVideoManager(CAdoConnection *pConn)
{
   m_pConn=pConn;
}

CVideoManager::~CVideoManager()
{

}
void CVideoManager::InsertVideo(CVideo v)
{
   CString strSql;
   strSql.Format("insert into videoInfo(videoName,videoDesp,videoPath,typeID) values ('%s','%s','%s',%d)",
		   v.strVideoName,v.strVideoDesp,v.strVideoPath,v.nTypeid);
   m_pConn->Execute(strSql);


}
void CVideoManager::UpdateVideo(CVideo nv,long videoID)
{
  CString strSql;
  strSql.Format("Update videoInfo set videoName='%s',videoDesp='%s',videoPath='%s',typeid=%d where id=%d",
	  nv.strVideoName,nv.strVideoDesp,nv.strVideoPath,nv.nTypeid,videoID);
  m_pConn->Execute(strSql);
}
void CVideoManager::DeleteVideo(long videoID)
{
	CString strSql;
	strSql.Format("delete from videoInfo where id=%d",videoID);
	m_pConn->Execute(strSql);
}
CString CVideoManager::GetVideoPathByID(long videoID)
{
	CString strSql;
	strSql.Format("select videoPath from videoInfo where id=%d",videoID);
	CAdoRecordSet set;
	set.SetAdoConnection(m_pConn);
	set.SetCursorLocation();
	set.Open(strSql);
	CString strVideoPath="";
	if (!set.IsEOF())
	{
		set.GetCollect("videoPath",strVideoPath);
	}
	return strVideoPath;
}

void CVideoManager::GetVideosByTypeID(long typeID,CList<CVideo,CVideo> *pLstVideo)
{
	
	CString strSql;
	strSql.Format("select id,videoName from videoinfo where typeid=%d",typeID);
	CAdoRecordSet set;
	set.SetAdoConnection(m_pConn);
	set.SetCursorLocation();
	set.Open(strSql);
	CVideo v;
	while(!set.IsEOF())
	{
		set.GetCollect("id",v.nVideoID);
		set.GetCollect("videoName",v.strVideoName);
		pLstVideo->AddTail(v);
		set.MoveNext();
	}
    
}