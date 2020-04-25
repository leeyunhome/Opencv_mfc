
// OpenCV_with_MFC2Dlg.h : header file
//

#pragma once


// COpenCVwithMFC2Dlg dialog
class COpenCVwithMFC2Dlg : public CDialogEx
{
// Construction
public:
	COpenCVwithMFC2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCV_WITH_MFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_picture;
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	VideoCapture* capture;
	Mat mat_frame;
	CImage cimage_mfc;
};
