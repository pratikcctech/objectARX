// exercise-9.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "exercise-9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void Cexercise9App::AddLine()
{
    // Get the current database 
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    // Open the Block Table for read-only
    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    // Get the Model Space block
    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();
    // Define the points that will be used to define the Line object
    AcGePoint3d startPt(7.0, 3.0, 0.0);
    AcGePoint3d endPt(11.0, 3.0, 0.0);
    // Create the new Line object in memory
    AcDbLine* pLine = new AcDbLine(startPt, endPt);
    // Add the new Line object to Model space
    pBlockTableRecord->appendAcDbEntity(pLine);
    // Close the Model space block
    pBlockTableRecord->close();
    // Close the new line object
    pLine->close();
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &Cexercise9App::AddLine);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// Cexercise9App

BEGIN_MESSAGE_MAP(Cexercise9App, CWinApp)
END_MESSAGE_MAP()


// Cexercise9App construction

Cexercise9App::Cexercise9App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cexercise9App object

Cexercise9App theApp;


// Cexercise9App initialization

BOOL Cexercise9App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
