// exercise-12.h : main header file for the exercise-12 DLL
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

// Cexercise12App
// See exercise-12.cpp for the implementation of this class
//

class Cexercise12App : public CWinApp
{
public:
	Cexercise12App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void userInfo();

	DECLARE_MESSAGE_MAP()
};
