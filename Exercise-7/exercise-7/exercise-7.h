// exercise-7.h : main header file for the exercise-7 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// Cexercise7App
// See exercise-7.cpp for the implementation of this class
//

class Cexercise7App : public CWinApp
{
public:
	Cexercise7App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void inputLine();

	DECLARE_MESSAGE_MAP()
};
