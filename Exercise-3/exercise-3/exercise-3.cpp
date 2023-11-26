// exercise-3.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "exercise-3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



//the feature defination of command
void Cexercise3App::MyCommand() {
    acutPrintf(_T("\n Hello this is pratik and welcome World of AutoCAD"));
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
        acedRegCmds->addCommand(L"AUCommands", _T("MyCommand"), _T("MyCommand"), ACRX_CMD_MODAL, &Cexercise3App::MyCommand);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}


BEGIN_MESSAGE_MAP(Cexercise3App, CWinApp)
END_MESSAGE_MAP()


// Cexercise3App construction

Cexercise3App::Cexercise3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cexercise3App object

Cexercise3App theApp;


// Cexercise3App initialization

BOOL Cexercise3App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
