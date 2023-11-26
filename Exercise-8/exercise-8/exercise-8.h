// exercise-8.h : main header file for the exercise-8 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise8App
// See exercise-8.cpp for the implementation of this class
//

class Cexercise8App : public CWinApp
{
public:
	Cexercise8App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void changeColor();

	DECLARE_MESSAGE_MAP()
};
