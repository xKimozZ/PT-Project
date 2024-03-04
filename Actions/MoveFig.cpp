#include "MoveFig.h"
#include "..\ApplicationManager.h"
MoveFig::MoveFig(ApplicationManager* pApp) :Action(pApp) {};

void MoveFig::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose where to move the Figure");

	//Read point and store in point P
	pIn->GetPointClicked(P.x, P.y);

}
//Execute the action
void MoveFig::Execute()
{
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	myFig = pManager->getSelectedfig();

	myFig->Move(P);
	
	//Add the Move to the list of actions
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}

};