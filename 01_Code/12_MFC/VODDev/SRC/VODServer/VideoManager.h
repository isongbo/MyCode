// VideoManager.h: interface for the CVideoManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOMANAGER_H__96A660D0_C1B6_4A35_8316_A862BFE364A2__INCLUDED_)
#define AFX_VIDEOMANAGER_H__96A660D0_C1B6_4A35_8316_A862BFE364A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include ".\ado\Ado.h"
struct CVideo
{
	int nVideoID;
	CString strVideoName;
    CString strVideoDesp;
	CString strVideoPath;
	int nTypeid;
};
class CVideoManager  
{
public:
	CVideoManager(CAdoConnection *pConn);
	virtual ~CVideoManager();
    void InsertVideo(CVideo v);
	void UpdateVideo(CVideo nv,long videoID);
	void DeleteVideo(long videoID);
	void GetVideosByTypeID(long typeID,CList<CVideo,CVideo> *pLstVideo);
	CString GetVideoPathByID(long videoID);
	CAdoConnection *m_pConn;
	CAdoRecordSet m_RecordSet;
};

#endif // !defined(AFX_VIDEOMANAGER_H__96A660D0_C1B6_4A35_8316_A862BFE364A2__INCLUDED_)
