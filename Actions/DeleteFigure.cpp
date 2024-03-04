#pragma once
#include "DeleteFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"

DeleteFigure::DeleteFigure(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteFigure::ReadActionParameters()
{
}

void DeleteFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedfig() == NULL)
	{
		pOut->PrintMessage("No figure selected, please choose figure to delete");
		return;
	}
	marked = pManager->getSelectedfig();
	pManager->DelFigure(marked);
	delete marked;
	pOut->PrintMessage("Figure Deleted");

	//Add delete operation to the list of actions
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}
}
 
 

