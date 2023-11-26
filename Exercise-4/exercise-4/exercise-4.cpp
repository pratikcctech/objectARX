// exercise-4.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "exercise-4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//the add line feature defination
void Cexercise4App::AddLine()
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &Cexercise4App::AddLine);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}
//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// Cexercise4App

BEGIN_MESSAGE_MAP(Cexercise4App, CWinApp)
END_MESSAGE_MAP()


// Cexercise4App construction

Cexercise4App::Cexercise4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cexercise4App object

Cexercise4App theApp;


// Cexercise4App initialization

BOOL Cexercise4App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
