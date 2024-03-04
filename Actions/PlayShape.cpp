#pragma once
#include "PlayShape.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


PlayShape::PlayShape(ApplicationManager*pApp) :Action(pApp)
{
	Target = 0, Incorrect = 0, Correct = 0, Rect = 0, Circ = 0, Square = 0, Tri = 0, Hex = 0;
}

void PlayShape::ReadActionParameters() //Count the occurences of each shape
{
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		pFig = pManager->PlayFigure(i);
		if (dynamic_cast<CRectangle*>(pFig))
			Rect++;
		else if (dynamic_cast<CCirc*>(pFig))
			Circ++;
		else if (dynamic_cast<CSquare*>(pFig))
			Square++;
		else if (dynamic_cast<CTriangle*>(pFig))
			Tri++;
		else Hex++;
	}
}

void PlayShape::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if ((pManager->GetFigCount() == Hex) || (pManager->GetFigCount() == Tri) || (pManager->GetFigCount() == Square) || (pManager->GetFigCount() == Circ) || (pManager->GetFigCount() == Rect))
		pOut->PrintMessage("At least 2 different shapes needed to play"); //Checks if all figures are not of one shape before starting
	else
	{
		CFigure* selectedfig;
		pFig = pManager->PlayFigure(rand() % pManager->GetFigCount()); //pick random figure
		if (dynamic_cast<CRectangle*>(pFig))							//Identify shape and instruct user to pick it
		{
			Target = Rect;
			pOut->PrintMessage("Pick all rectangles");

		}
		else if (dynamic_cast<CCirc*>(pFig))
		{
			Target = Circ;
			pOut->PrintMessage("Pick all circles");

		}
		else if (dynamic_cast<CSquare*>(pFig))
		{
			Target = Square;
			pOut->PrintMessage("Pick all squares");

		}
		else if (dynamic_cast<CTriangle*>(pFig))
		{
			Target = Tri;
			pOut->PrintMessage("Pick all triangles");

		}
		else
		{
			Target = Hex;
			pOut->PrintMessage("Pick all hexagons");
		}

		int finTarget = Target; //Copy of figure count to be used in grading

		while (0 < Target)
		{
			pIn->GetPointClicked(click.x, click.y);
			selectedfig = pManager->GetFigure(click.x, click.y);
			if (click.y > UI.ToolBarHeight || (click.x > (UI.MenuItemWidth * (ITM_SHAPES+1)) || click.x < (UI.MenuItemWidth * ITM_SHAPES)) ) //Game keeps running unless icon is selected
			{
				if (selectedfig != NULL && selectedfig->IsHidden() == false)
				{

					if ((dynamic_cast<CRectangle*>(selectedfig)) && (dynamic_cast<CRectangle*>(pFig)))
					{
						Correct++;
						selectedfig->SetHidden(true);
						pManager->UpdateInterface();
						Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
						pOut->PrintMessage(Status);
						Target--;
					}
					else if ((dynamic_cast<CCirc*>(selectedfig)) && (dynamic_cast<CCirc*>(pFig)))
					{
						Correct++;
						selectedfig->SetHidden(true);
						pManager->UpdateInterface();
						Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
						pOut->PrintMessage(Status);
						Target--;
					}
					else if ((dynamic_cast<CSquare*>(selectedfig)) && (dynamic_cast<CSquare*>(pFig)))
					{
						Correct++;
						selectedfig->SetHidden(true);
						pManager->UpdateInterface();
						Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
						pOut->PrintMessage(Status);
						Target--;
					}
					else if ((dynamic_cast<CTriangle*>(selectedfig)) && (dynamic_cast<CTriangle*>(pFig)))
					{
						Correct++;
						selectedfig->SetHidden(true);
						pManager->UpdateInterface();
						Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
						pOut->PrintMessage(Status);
						Target--;
					}
					else if ((dynamic_cast<CHexagon*>(selectedfig)) && (dynamic_cast<CHexagon*>(pFig)))
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
				float Grade = (float)Correct / ((float)finTarget+(float)Incorrect) * 100;
				Status = "Game complete	    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect) + "    Grade: " + to_string((int)Grade)+"/100";
				pOut->PrintMessage(Status);
			}
		}

		for (int i = 0; i < pManager->GetFigCount(); i++)
			pManager->PlayFigure(i)->SetHidden(false);
		pManager->UpdateInterface();

	}
}