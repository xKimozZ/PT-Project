#include "AddSqrAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}
 

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at a center point");

	//Read point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	

	SqrGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
 
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
		//Create a square with the parameters read from the user
		CSquare* R = new CSquare(P, SqrGfxInfo);

		//Add the square to the list of figures
		pManager->AddFigure(R);

	
	//Add the Square to the list of actions
	if (pManager->GetRec() == true)
	{
		  
		pManager->AddAction();

	}
	if(pManager->getMute()==false && pManager->getIsPlaying()==false) PlaySound(TEXT("Square.wav"),NULL,SND_SYNC);
}
