// exercise-5.h : main header file for the exercise-5 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>


// Cexercise5App
// See exercise-5.cpp for the implementation of this class
//

class Cexercise5App : public CWinApp
{
public:
	Cexercise5App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void makeLayer();

	DECLARE_MESSAGE_MAP()
};
