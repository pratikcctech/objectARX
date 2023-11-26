// Exercise-10.h : main header file for the Exercise-10 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise10App
// See Exercise-10.cpp for the implementation of this class
//

class CExercise10App : public CWinApp
{
public:
	CExercise10App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void AddLine();

	DECLARE_MESSAGE_MAP()
};
