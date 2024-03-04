#include "AddTriAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third point");

	//Read 3rd point and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	TriGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()

{
	 
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
		//Create a triangle with the parameters read from the user
		CTriangle* R = new CTriangle(P1, P2, P3, TriGfxInfo);

		//Add the trinagle to the list of figures
		pManager->AddFigure(R);
	 
	//Add the Triangle to the list of actions
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}
	if(pManager->getMute()==false && pManager->getIsPlaying()==false) PlaySound(TEXT("Triangle.wav"),NULL,SND_SYNC);

}
