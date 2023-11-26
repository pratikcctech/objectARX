// exercise-6.h : main header file for the exercise-6 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise6App
// See exercise-6.cpp for the implementation of this class
//

class Cexercise6App : public CWinApp
{
public:
	Cexercise6App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void listObjects();

	DECLARE_MESSAGE_MAP()
};
