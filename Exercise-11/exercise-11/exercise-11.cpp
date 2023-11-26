// exercise-11.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "exercise-11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//define a function named commandAndSysVar defination
void Cexercise11App::commandAndSysVar()
{
	// Create a variable of the result buffer type
	struct resbuf rb, rb1;
	// Get the current value of the CIRCLERAD system variable
	acedGetVar(_T("CIRCLERAD"), &rb);
	acutPrintf(_T("\nCurrent CIRCLERAD: %.2f\n"), rb.resval);
	// Define the center point for the circle
	ads_point pt;
	pt[X] = 2.5; pt[Y] = 3.75; pt[Z] = 0.0;
	// Define the radius of the circle
	double rrad = 2.75;
	// Provide all values to the CIRCLE command
	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTPOINT, pt,
		RTREAL, rrad, RTNONE) != RTNORM)
	{
		acutPrintf(_T("\nError: CIRCLE command failed."));
	}// Pause for the center point
	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTSTR, PAUSE,
		RTREAL, rrad, RTNONE) != RTNORM)
	{
		acutPrintf(_T("\nError: CIRCLE command failed."));
	}
	// Set the value of CIRCLERAD to the previous value
	rb1.restype = RTREAL;
	rb1.resval.rreal = rb.resval.rreal;
	acedSetVar(_T("CIRCLERAD"), &rb1);
}

extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        // below line for registering new command
		acedRegCmds->addCommand(_T("AUCommands"), _T("CommandAndSysVar"), _T("CommandAndSysVar"), ACRX_CMD_MODAL, &Cexercise11App::commandAndSysVar);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// Cexercise11App

BEGIN_MESSAGE_MAP(Cexercise11App, CWinApp)
END_MESSAGE_MAP()


// Cexercise11App construction

Cexercise11App::Cexercise11App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cexercise11App object

Cexercise11App theApp;


// Cexercise11App initialization

BOOL Cexercise11App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
