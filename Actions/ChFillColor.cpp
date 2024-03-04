#include "DrawingColor.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "Action.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include "../Figures/CFigure.h"
#include "../GUI/UI_Info.h"
#include "ChFillColor.h"
ChFillColor::ChFillColor(ApplicationManager *pApp):Action(pApp)
{
	
}
void ChFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("You Will change Fill Color");
	Ctype=pIn->GetUserAction();
	pOut->ClearStatusBar();
}
void ChFillColor::Execute()
{
	 
	 
	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}

		myfig = pManager->getSelectedfig();


		switch (Ctype)
		{
		case C_RED:
			myfig->ChngFillClr(RED);
			UI.FillColor = RED;
			break;
		case C_GREEN:
			myfig->ChngFillClr(GREEN);
			UI.FillColor = GREEN;
			break;
		case C_BLUE:
			myfig->ChngFillClr(BLUE);
			UI.FillColor = BLUE;
			break;
		case C_YELLOW:
			myfig->ChngFillClr(YELLOW);
			UI.FillColor = YELLOW;
			break;
		case C_ORANGE:
			myfig->ChngFillClr(ORANGE);
			UI.FillColor = ORANGE;
			break;
		case C_BLACK:
			myfig->ChngFillClr(BLACK);
			UI.FillColor = BLACK;
			break;
		default:
			break;
		}
	
	//Add the FillColor to the list of actions
		if(pManager->GetRec() == true)
		{
			pManager->AddAction();
		}
	
}