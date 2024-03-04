#pragma once
#include "PlayColor.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


PlayColor::PlayColor(ApplicationManager*pApp) :Action(pApp)
{
	Target = 0, Incorrect = 0, Correct = 0, Black = 0, Yellow = 0, Orange = 0, Blue = 0, Green = 0, Red = 0;
}

void PlayColor::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		pFig = pManager->PlayFigure(i);
		if (pFig->getGfxInfo().isFilled == true)
		{
			if		(pFig->getGfxInfo().FillClr == BLACK)
				Black++;
			else if (pFig->getGfxInfo().FillClr == YELLOW)
				Yellow++;
			else if (pFig->getGfxInfo().FillClr == ORANGE)
				Orange++;
			else if (pFig->getGfxInfo().FillClr == BLUE)
				Blue++;
			else if (pFig->getGfxInfo().FillClr == GREEN)
				Green++;
			else if (pFig->getGfxInfo().FillClr == RED)
				Red++;
		}
		else if (pFig->getGfxInfo().isFilled == false)
		{
			{
				if (pFig->getGfxInfo().DrawClr == BLACK)
				Black++;
				else if (pFig->getGfxInfo().DrawClr == YELLOW)
					Yellow++;
				else if (pFig->getGfxInfo().DrawClr == ORANGE)
					Orange++;
				else if (pFig->getGfxInfo().DrawClr == BLUE)
					Blue++;
				else if (pFig->getGfxInfo().DrawClr == GREEN)
					Green++;
				else if (pFig->getGfxInfo().DrawClr == RED)
					Red++;
			}
		}
	}
}

void PlayColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if ((pManager->GetFigCount() == Black) || (pManager->GetFigCount() == Yellow) || (pManager->GetFigCount() == Orange) || (pManager->GetFigCount() == Blue) || (pManager->GetFigCount() == Green) || (pManager->GetFigCount()== Red))
	pOut->PrintMessage("At least 2 different colours needed to play");
	else
	{
		CFigure* previous = pManager->getSelectedfig();
		if (previous != NULL && previous->IsSelected() == 1)//If a figure was selected, it is deselected to prevent confusion
		{
			previous->SetSelected(false);
			pManager->setSelectedfig(NULL);
			pManager->UpdateInterface();
		}
	CFigure* selectedfig;
	pFig = pManager->PlayFigure(rand() % pManager->GetFigCount()); //pick random figure
	if (pFig->getGfxInfo().isFilled == true)						//Fill color is prioritised over draw color
	{
		if (pFig->getGfxInfo().FillClr == BLACK)
		{
			Target = Black;
			chosen = BLACK;
			pOut->PrintMessage("Pick black figures");
		}
		else if (pFig->getGfxInfo().FillClr == YELLOW)
		{
			Target = Yellow;
			chosen = YELLOW;
			pOut->PrintMessage("Pick yellow figures");
		}
		else if (pFig->getGfxInfo().FillClr == ORANGE)
		{
			Target = Orange;
			chosen = ORANGE;
			pOut->PrintMessage("Pick orange figures");
		}
		else if (pFig->getGfxInfo().FillClr == BLUE)
		{
			Target = Blue;
			chosen = BLUE;
			pOut->PrintMessage("Pick blue figures");
		}
		else if (pFig->getGfxInfo().FillClr == GREEN)
		{
			Target = Green;
			chosen = GREEN;
			pOut->PrintMessage("Pick green figures");
		}
		else if (pFig->getGfxInfo().FillClr == RED)
		{
			Target = Red;
			chosen = RED;
			pOut->PrintMessage("Pick red figures");
		}
	}
	else if (pFig->getGfxInfo().isFilled == false)		//If the figure is not filled, its draw color is taken instead
	{
		{
			if (pFig->getGfxInfo().DrawClr == BLACK)
			{
				Target = Black;
				chosen = BLACK;
				pOut->PrintMessage("Pick black figures");
			}
			else if (pFig->getGfxInfo().DrawClr == YELLOW)
			{
				Target = Yellow;
				chosen = YELLOW;
				pOut->PrintMessage("Pick yellow figures");
			}
			else if (pFig->getGfxInfo().DrawClr == ORANGE)
			{
				Target = Orange;
				chosen = ORANGE;
				pOut->PrintMessage("Pick orange figures");
			}
			else if (pFig->getGfxInfo().DrawClr == BLUE)
			{
				Target = Blue;
				chosen = BLUE;
				pOut->PrintMessage("Pick blue figures");
			}
			else if (pFig->getGfxInfo().DrawClr == GREEN)
			{
				Target = Green;
				chosen = GREEN;
				pOut->PrintMessage("Pick green figures");
			}
			else if (pFig->getGfxInfo().DrawClr == RED)
			{
				Target = Red;
				chosen = RED;
				pOut->PrintMessage("Pick red figures");
			}
		}
	}

	int finTarget = Target; //Copy of figure count to be used in grading

	while (0 < Target)
	{
	pIn->GetPointClicked(click.x, click.y);
	selectedfig = pManager->GetFigure(click.x, click.y);
	if (click.y > UI.ToolBarHeight || (click.x > (UI.MenuItemWidth * (ITM_COLOURS + 1)) || click.x < (UI.MenuItemWidth * ITM_COLOURS)) ) //Game keeps running unless icon is selected
	{
	if (selectedfig != NULL && selectedfig->IsHidden() == false)
	{

	if ((selectedfig->getGfxInfo().isFilled==true && pFig->getGfxInfo().isFilled==true)&&(selectedfig->getGfxInfo().FillClr==chosen))
	{
	Correct++;
	selectedfig->SetHidden(true);
	pManager->UpdateInterface();
	Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
	pOut->PrintMessage(Status);
	Target--;
	}
	else if ((selectedfig->getGfxInfo().isFilled == false && pFig->getGfxInfo().isFilled == true) && (selectedfig->getGfxInfo().DrawClr == chosen))
	{
	Correct++;
	selectedfig->SetHidden(true);
	pManager->UpdateInterface();
	Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
	pOut->PrintMessage(Status);
	Target--;
	}
	else if ((selectedfig->getGfxInfo().isFilled == true && pFig->getGfxInfo().isFilled == false) && (selectedfig->getGfxInfo().FillClr == chosen))
	{
	Correct++;
	selectedfig->SetHidden(true);
	pManager->UpdateInterface();
	Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
	pOut->PrintMessage(Status);
	Target--;
	}
	else if ((selectedfig->getGfxInfo().isFilled == false && pFig->getGfxInfo().isFilled == false) && (selectedfig->getGfxInfo().DrawClr == chosen))
	{
	Correct++;
	selectedfig->SetHidden(true);
	pManager->UpdateInterface();
	Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
	pOut->PrintMessage(Status);
	Target--;
	}
	else
	{
	Incorrect++;
	selectedfig->SetHidden(true);
	pManager->UpdateInterface();
	Status = "Wrong shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
	pOut->PrintMessage(Status);
	}
	}
	}
	else
	{
	pOut->PrintMessage("Game closed, click icon again to restart");
	Target = -1; //to prevent game from going to score screen
	} 
	if (Target == 0)
	{
	float Grade = (float)Correct / ((float)finTarget + (float)Incorrect) * 100;
	Status = "Game complete	    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect) + "    Grade: " + to_string((int)Grade) + "/100";
	pOut->PrintMessage(Status);
	}
	}

	for (int i = 0; i < pManager->GetFigCount(); i++)
	pManager->PlayFigure(i)->SetHidden(false);
	pManager->UpdateInterface();

	}
}