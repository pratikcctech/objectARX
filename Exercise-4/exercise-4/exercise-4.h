// exercise-4.h : main header file for the exercise-4 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise4App
// See exercise-4.cpp for the implementation of this class
//

class Cexercise4App : public CWinApp
{
public:
	Cexercise4App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void AddLine();

	DECLARE_MESSAGE_MAP()
};
