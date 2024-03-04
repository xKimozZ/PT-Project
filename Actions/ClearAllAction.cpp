#include"ClearAllAction.h"
#include "../GUI/Output.h"
#include "../DEFS.h"
#include "../GUI/UI_Info.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{

}
void ClearAllAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cleared all");
}
void ClearAllAction::Execute()
{

	ReadActionParameters();
	pManager->ClearAll();
	pManager->UpdateInterface();
	
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}

}
void ClearAllAction::Undo()
{

}