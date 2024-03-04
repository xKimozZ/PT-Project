#pragma once
#include "AddCircAction.h"
#include"..\figures\CCirc.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include <mmsystem.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second Point");

	//Read point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	
	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	 
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

		//Create a circle with the parameters read from the user
		CCirc* R = new CCirc(P1, P2, CircGfxInfo);

		//Add the circle to the list of figures
		pManager->AddFigure(R);
	
	//Add the circle to the list of actions
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}
	if(pManager->getMute()==false && pManager->getIsPlaying()==false) PlaySound(TEXT("Circ.wav"),NULL,SND_SYNC);
	
}
