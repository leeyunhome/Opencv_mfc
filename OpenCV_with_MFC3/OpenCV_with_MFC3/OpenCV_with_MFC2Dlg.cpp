
// OpenCV_with_MFC2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OpenCV_with_MFC2.h"
#include "OpenCV_with_MFC2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenCVwithMFC2Dlg dialog



COpenCVwithMFC2Dlg::COpenCVwithMFC2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCV_WITH_MFC2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCVwithMFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
}

BEGIN_MESSAGE_MAP(COpenCVwithMFC2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
//	ON_WM_TIMER()
ON_BN_CLICKED(IDC_IMG_LOAD_BTN, &COpenCVwithMFC2Dlg::OnBnClickedImgLoadBtn)
END_MESSAGE_MAP()


// COpenCVwithMFC2Dlg message handlers

BOOL COpenCVwithMFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//img = imread("hodu5.jpg");

	//if (img.empty())
	//{
	//	std::cerr << "Image load failed!" << std::endl;
	//	return -1;
	//}
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COpenCVwithMFC2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COpenCVwithMFC2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		img = imread("school.png", IMREAD_UNCHANGED);

		rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 255, 0), 2);
		CreateBitmapInfo(img.cols, img.rows, img.channels() * 8);

		DrawImage();

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COpenCVwithMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenCVwithMFC2Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
}


//void COpenCVwithMFC2Dlg::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: Add your message handler code here and/or call default
//	cvtColor(img, img, COLOR_BGR2GRAY);
//
//
//	int bpp = 8 * img.elemSize();
//	assert((bpp == 8 || bpp == 24 || bpp == 32));
//
//	int padding = 0;
//	//32 bit image is always DWORD aligned because each pixel requires 4 bytes
//	if (bpp < 32)
//		padding = 4 - (img.cols % 4);
//
//	if (padding == 4)
//		padding = 0;
//
//	int border = 0;
//	//32 bit image is always DWORD aligned because each pixel requires 4 bytes
//	if (bpp < 32)
//	{
//		border = 4 - (img.cols % 4);
//	}
//
//	Mat mat_temp;
//	if (border > 0 || img.isContinuous() == false)
//	{
//		// Adding needed columns on the right (max 3 px)
//		cv::copyMakeBorder(img, mat_temp, 0, 0, 0, border, cv::BORDER_CONSTANT, 0);
//	}
//	else
//	{
//		mat_temp = img;
//	}
//
//	RECT r;
//	m_picture.GetClientRect(&r);
//	cv::Size winSize(r.right, r.bottom);
//
//	cimage_mfc.Create(winSize.width, winSize.height, 24);
//
//	BITMAPINFO* bitInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
//	bitInfo->bmiHeader.biBitCount = bpp;
//	bitInfo->bmiHeader.biWidth = mat_temp.cols;
//	bitInfo->bmiHeader.biHeight = -mat_temp.rows;
//	bitInfo->bmiHeader.biPlanes = 1;
//	bitInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
//	bitInfo->bmiHeader.biCompression = BI_RGB;
//	bitInfo->bmiHeader.biClrImportant = 0;
//	bitInfo->bmiHeader.biClrUsed = 0;
//	bitInfo->bmiHeader.biSizeImage = 0;
//	bitInfo->bmiHeader.biXPelsPerMeter = 0;
//	bitInfo->bmiHeader.biYPelsPerMeter = 0;
//
//	//그레이스케일 인경우 팔레트가 필요
//	if (bpp == 8)
//	{
//		RGBQUAD* palette = bitInfo->bmiColors;
//		for (int i = 0; i < 256; i++)
//		{
//			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
//			palette[i].rgbReserved = 0;
//		}
//	}
//
//
//	// Image is bigger or smaller than into destination rectangle
//	// we use stretch in full rect
//
//	if (mat_temp.cols == winSize.width && mat_temp.rows == winSize.height)
//	{
//		// source and destination have same size
//		// transfer memory block
//		// NOTE: the padding border will be shown here. Anyway it will be max 3px width
//
//		SetDIBitsToDevice(cimage_mfc.GetDC(),
//			//destination rectangle
//			0, 0, winSize.width, winSize.height,
//			0, 0, 0, mat_temp.rows,
//			mat_temp.data, bitInfo, DIB_RGB_COLORS);
//	}
//	else
//	{
//		// destination rectangle
//		int destx = 0, desty = 0;
//		int destw = winSize.width;
//		int desth = winSize.height;
//
//		// rectangle defined on source bitmap
//		// using imgWidth instead of mat_temp.cols will ignore the padding border
//		int imgx = 0, imgy = 0;
//		int imgWidth = mat_temp.cols - border;
//		int imgHeight = mat_temp.rows;
//
//		StretchDIBits(cimage_mfc.GetDC(),
//			destx, desty, destw, desth,
//			imgx, imgy, imgWidth, imgHeight,
//			mat_temp.data, bitInfo, DIB_RGB_COLORS, SRCCOPY);
//	}
//
//
//	HDC dc = ::GetDC(m_picture.m_hWnd);
//	cimage_mfc.BitBlt(dc, 0, 0);
//
//
//	::ReleaseDC(m_picture.m_hWnd, dc);
//
//	cimage_mfc.ReleaseDC();
//	cimage_mfc.Destroy();
//
//	CDialogEx::OnTimer(nIDEvent);
//}

void COpenCVwithMFC2Dlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete[]m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}

void COpenCVwithMFC2Dlg::DrawImage()
{
	CClientDC dc(GetDlgItem(IDC_PICTURE));

	CRect rect;
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, img.cols, img.rows, img.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}

void COpenCVwithMFC2Dlg::OnBnClickedImgLoadBtn()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);

		img = imread(strPath, IMREAD_UNCHANGED);
		//cvtColor(img, img, COLOR_BGR2GRAY);
		//
		//line(img, Point(350, 350), Point(370, 50), Scalar(0, 0, 255));
		//line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
		//drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_CROSS);
		rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 255, 0), 2);
		CreateBitmapInfo(img.cols, img.rows, img.channels() * 8);

		DrawImage();
	}
}
