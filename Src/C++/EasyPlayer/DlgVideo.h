#pragma once

#include "DlgRender.h"
// CDlgVideo �Ի���


#include <afxdialogex.h>

#include "../libEasyPlayer/libEasyPlayerAPI.h"


class CDlgVideo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgVideo)

public:
	CDlgVideo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgVideo();

	CString  GetRtspUrl(int i);
	void	SetWindowId(int _windowId);
	void	SetShownToScale(int shownToScale);
	void	SetURL(char *url);

	bool	bDrag;

	bool m_bDestoryWnd;
	int		m_WindowId;
	int		m_ChannelId;
	CDlgRender	*pDlgRender;
	CEdit	*pEdtURL;		//IDC_EDIT_RTSP_URL
	CButton	*pChkOSD;		//IDC_CHECK_OSD
	CButton	*pChkRTPTransMode;		//IDC_CHECK_RTPTRANSMODE
	CButton* pChkDecodeMode;
	CSliderCtrl	*pSliderCache;	//IDC_SLIDER_CACHE
	CButton	*pBtnPreview;	//IDC_BUTTON_PREVIEW
	CButton	*pBtnSeek;	//IDC_BUTTON_PREVIEW
	void	InitialComponents();
	void	CreateComponents();
	void	UpdateComponents();
	void	DeleteComponents();
	void LogErr(CString strLog);

// �Ի�������
	enum { IDD = IDD_DIALOG_VIDEO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonPreview();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedCheckOsd();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedCheckRtptransmode();
//	afx_msg void OnBnClickedButtonSeek();

public:
	static int CALLBACK EasyPlayerCallBack( int _channelId, int *_channelPtr, int _frameType, char *pBuf, EASY_FRAME_INFO* _frameInfo);
};
