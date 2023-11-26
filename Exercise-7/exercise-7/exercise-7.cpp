// exercise-7.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "exercise-7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// the feature Add a Line Using User Input function defination
void Cexercise7App::inputLine()
{
	// Get the current space block
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForWrite);
	// Create 2 variables of the old point data type
	ads_point pt1, pt2;
	// Prompt for the first point
	if (RTNORM == acedGetPoint(NULL, _T("\nSpecify first point: "), pt1))
	{
		AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);
		// Prompt for the second point
		if (RTNORM == acedGetPoint(pt1,
			_T("\nSpecify second point: "), pt2))
		{
			AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);
			// Create and append the new Line object
			AcDbLine* pLine = new AcDbLine(startPt, endPt);
			pBlockTableRecord->appendAcDbEntity(pLine);
			// Close the block table record and the Line object
			pBlockTableRecord->close();
			pLine->close();
		}
	}
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
		acedRegCmds->addCommand(_T("AUCommands"), _T("InputLine"), _T("InputLine"), ACRX_CMD_MODAL, &Cexercise7App::inputLine);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}


BEGIN_MESSAGE_MAP(Cexercise7App, CWinApp)
END_MESSAGE_MAP()


// Cexercise7App construction

Cexercise7App::Cexercise7App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cexercise7App object

Cexercise7App theApp;


// Cexercise7App initialization

BOOL Cexercise7App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
