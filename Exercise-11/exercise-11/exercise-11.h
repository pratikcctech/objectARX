// exercise-11.h : main header file for the exercise-11 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>
#include "acedCmdNF.h"

// Cexercise11App
// See exercise-11.cpp for the implementation of this class
//

class Cexercise11App : public CWinApp
{
public:
	Cexercise11App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void commandAndSysVar();

	DECLARE_MESSAGE_MAP()
};
