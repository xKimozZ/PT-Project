#include "AddHexaAction.h"

#include "..\Figures/CFigure.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at a center point");

	//Read point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	
	HexaGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	 
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

	//Create a hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(P, HexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(R);
	 
	//Add the Hexagon to the list of actions
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}
	if(pManager->getMute()==false && pManager->getIsPlaying()==false) PlaySound(TEXT("Hex.wav"),NULL,SND_SYNC);
}