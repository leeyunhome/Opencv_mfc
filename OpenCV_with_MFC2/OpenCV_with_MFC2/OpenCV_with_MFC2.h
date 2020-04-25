
// OpenCV_with_MFC2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COpenCVwithMFC2App:
// See OpenCV_with_MFC2.cpp for the implementation of this class
//

class COpenCVwithMFC2App : public CWinApp
{
public:
	COpenCVwithMFC2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COpenCVwithMFC2App theApp;
