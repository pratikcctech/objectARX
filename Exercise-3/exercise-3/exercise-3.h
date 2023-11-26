// exercise-3.h : main header file for the exercise-3 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise3App
// See exercise-3.cpp for the implementation of this class
//

class Cexercise3App : public CWinApp
{
public:
	Cexercise3App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void MyCommand();

	DECLARE_MESSAGE_MAP()
};
