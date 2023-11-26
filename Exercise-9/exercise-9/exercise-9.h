// exercise-9.h : main header file for the exercise-9 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise9App
// See exercise-9.cpp for the implementation of this class
//

class Cexercise9App : public CWinApp
{
public:
	Cexercise9App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void AddLine();

	DECLARE_MESSAGE_MAP()
};
