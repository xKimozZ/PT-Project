#include "DrawingColor.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "Action.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include "../GUI/UI_Info.h"
DrawingColor::DrawingColor(ApplicationManager *pApp):Action(pApp)
{
	
}
void DrawingColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("You Will change Drawing Color");
	Ctype=pIn->GetUserAction();
	pOut->ClearStatusBar();
}
void DrawingColor::Execute()
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
			myfig->ChngDrawClr(RED);
			UI.DrawColor = RED;
			break;
		case C_GREEN:
			myfig->ChngDrawClr(GREEN);
			UI.DrawColor = GREEN;
			break;
		case C_BLUE:
			myfig->ChngDrawClr(BLUE);
			UI.DrawColor = BLUE;
			break;
		case C_YELLOW:
			myfig->ChngDrawClr(YELLOW);
			UI.DrawColor = YELLOW;
			break;
		case C_ORANGE:
			myfig->ChngDrawClr(ORANGE);
			UI.DrawColor = ORANGE;
			break;
		case C_BLACK:
			myfig->ChngDrawClr(BLACK);
			UI.DrawColor = BLACK;
			break;
		default:
			break;
		}
	
	//Add the Drawing to the list of actions
		if (pManager->GetRec() == true)
		{
			pManager->AddAction();
		}
	
}