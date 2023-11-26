// exercise-1.h : main header file for the exercise-1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise1App
// See exercise-1.cpp for the implementation of this class
//

class Cexercise1App : public CWinApp
{
public:
	Cexercise1App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void AddLine();
	DECLARE_MESSAGE_MAP()
};
