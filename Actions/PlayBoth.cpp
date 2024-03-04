#pragma once
#include "PlayBoth.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


PlayBoth::PlayBoth(ApplicationManager*pApp) :Action(pApp)
{
	Number = 0, Target = 0, Incorrect = 0, Correct = 0;
	for (int i=0; i < 30; i++)
		Chance[i] = 0;
}

void PlayBoth::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		pFig = pManager->PlayFigure(i);
		if (pFig->getGfxInfo().isFilled == true)			//Since filled figure's colors are prioritised, they're checked first
		{													//Then, shapes are identified. Possibilities array is then updated
			if (pFig->getGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[0]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[1]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[2]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[3]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[4]++;
			}
			else if (pFig->getGfxInfo().FillClr == YELLOW)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[5]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[6]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[7]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[8]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[9]++;
			}
			else if (pFig->getGfxInfo().FillClr == ORANGE)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[10]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[11]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[12]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[13]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[14]++;
			}
			else if (pFig->getGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[15]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[16]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[17]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[18]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[19]++;
			}
			else if (pFig->getGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[20]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[21]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[22]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[23]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[24]++;
			}
			else if (pFig->getGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CRectangle*>(pFig))
					Chance[25]++;
				else if (dynamic_cast<CCirc*>(pFig))
					Chance[26]++;
				else if (dynamic_cast<CSquare*>(pFig))
					Chance[27]++;
				else if (dynamic_cast<CTriangle*>(pFig))
					Chance[28]++;
				else if (dynamic_cast<CHexagon*>(pFig))
					Chance[29]++;
			}
		}
		else if (pFig->getGfxInfo().isFilled == false)			//If unfilled, they're checked again, and the matching combination is put into it's respective place in the array
		{
			{
				if (pFig->getGfxInfo().DrawClr == BLACK)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[0]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[1]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[2]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[3]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[4]++;
				}
				else if (pFig->getGfxInfo().DrawClr == YELLOW)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[5]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[6]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[7]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[8]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[9]++;
				}
				else if (pFig->getGfxInfo().DrawClr == ORANGE)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[10]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[11]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[12]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[13]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[14]++;
				}
				else if (pFig->getGfxInfo().DrawClr == BLUE)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[15]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[16]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[17]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[18]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[19]++;
				}
				else if (pFig->getGfxInfo().DrawClr == GREEN)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[20]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[21]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[22]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[23]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[24]++;
				}
				else if (pFig->getGfxInfo().DrawClr == RED)
				{
					if (dynamic_cast<CRectangle*>(pFig))
						Chance[25]++;
					else if (dynamic_cast<CCirc*>(pFig))
						Chance[26]++;
					else if (dynamic_cast<CSquare*>(pFig))
						Chance[27]++;
					else if (dynamic_cast<CTriangle*>(pFig))
						Chance[28]++;
					else if (dynamic_cast<CHexagon*>(pFig))
						Chance[29]++;
				}
			}
		}
	}
	for (int i = 0; i < 30; i++)
	if (Chance[i]!=0)		//If combination happened at least once, the number of occured combination increases by one
		Number++;
}

void PlayBoth::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (Number <2)			//Check if combinations are not unique
		pOut->PrintMessage("At least 2 different combinations needed to play");
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
		if (pFig->getGfxInfo().isFilled == true)				//Filled figure color prioritised
		{
			if (pFig->getGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[0];
					pOut->PrintMessage("Pick black rectangles"); chosen = BLACK;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[1];
					pOut->PrintMessage("Pick black circles"); chosen = BLACK;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[2];
					pOut->PrintMessage("Pick black squares"); chosen = BLACK;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[3];
					pOut->PrintMessage("Pick black triangles"); chosen = BLACK;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[4];
					pOut->PrintMessage("Pick black hexagons"); chosen = BLACK;
				}
			}
			else if (pFig->getGfxInfo().FillClr == YELLOW)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[5];
					pOut->PrintMessage("Pick yellow rectangles"); chosen = YELLOW;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[6];
					pOut->PrintMessage("Pick yellow circles"); chosen = YELLOW;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[7];
					pOut->PrintMessage("Pick yellow squares"); chosen = YELLOW;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[8];
					pOut->PrintMessage("Pick yellow triangles"); chosen = YELLOW;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[9];
					pOut->PrintMessage("Pick yellow hexagons"); chosen = YELLOW;
				}
			}
			else if (pFig->getGfxInfo().FillClr == ORANGE)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[10];
					pOut->PrintMessage("Pick orange rectangles"); chosen = ORANGE;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[11];
					pOut->PrintMessage("Pick orange circles"); chosen = ORANGE;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[12];
					pOut->PrintMessage("Pick orange squares"); chosen = ORANGE;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[13];
					pOut->PrintMessage("Pick orange triangles"); chosen = ORANGE;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[14];
					pOut->PrintMessage("Pick orange hexagons"); chosen = ORANGE;
				}
			}
			else if (pFig->getGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[15];
					pOut->PrintMessage("Pick blue rectangles"); chosen = BLUE;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[16];
					pOut->PrintMessage("Pick blue circles"); chosen = BLUE;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[17];
					pOut->PrintMessage("Pick blue squares"); chosen = BLUE;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[18];
					pOut->PrintMessage("Pick blue triangles"); chosen = BLUE;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[19];
					pOut->PrintMessage("Pick blue hexagons"); chosen = BLUE;
				}
			}
			else if (pFig->getGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[20];
					pOut->PrintMessage("Pick green rectangles"); chosen = GREEN;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[21];
					pOut->PrintMessage("Pick green circles"); chosen = GREEN;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[22];
					pOut->PrintMessage("Pick green squares"); chosen = GREEN;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[23];
					pOut->PrintMessage("Pick green triangles"); chosen = GREEN;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[24];
					pOut->PrintMessage("Pick green hexagons"); chosen = GREEN;
				}
			}
			else if (pFig->getGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CRectangle*>(pFig))
				{
					Target = Chance[25];
					pOut->PrintMessage("Pick red rectangles"); chosen = RED;
				}
				else if (dynamic_cast<CCirc*>(pFig))
				{
					Target = Chance[26];
					pOut->PrintMessage("Pick red circles"); chosen = RED;
				}
				else if (dynamic_cast<CSquare*>(pFig))
				{
					Target = Chance[27];
					pOut->PrintMessage("Pick red squares"); chosen = RED;
				}
				else if (dynamic_cast<CTriangle*>(pFig))
				{
					Target = Chance[28];
					pOut->PrintMessage("Pick red triangles"); chosen = RED;
				}
				else if (dynamic_cast<CHexagon*>(pFig))
				{
					Target = Chance[29];
					pOut->PrintMessage("Pick red hexagons"); chosen = RED;
				}
			}
		}
		else
		{
				if (pFig->getGfxInfo().DrawClr == BLACK)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[0];
						pOut->PrintMessage("Pick black rectangles"); chosen = BLACK;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[1];
						pOut->PrintMessage("Pick black circles"); chosen = BLACK;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[2];
						pOut->PrintMessage("Pick black squares"); chosen = BLACK;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[3];
						pOut->PrintMessage("Pick black triangles"); chosen = BLACK;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[4];
						pOut->PrintMessage("Pick black hexagons"); chosen = BLACK;
					}
				}
				else if (pFig->getGfxInfo().DrawClr == YELLOW)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[5];
						pOut->PrintMessage("Pick yellow rectangles"); chosen = YELLOW;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[6];
						pOut->PrintMessage("Pick yellow circles"); chosen = YELLOW;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[7];
						pOut->PrintMessage("Pick yellow squares"); chosen = YELLOW;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[8];
						pOut->PrintMessage("Pick yellow triangles"); chosen = YELLOW;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[9];
						pOut->PrintMessage("Pick yellow hexagons"); chosen = YELLOW;
					}
				}
				else if (pFig->getGfxInfo().DrawClr == ORANGE)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[10];
						pOut->PrintMessage("Pick orange rectangles"); chosen = ORANGE;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[11];
						pOut->PrintMessage("Pick orange circles"); chosen = ORANGE;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[12];
						pOut->PrintMessage("Pick orange squares"); chosen = ORANGE;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[13];
						pOut->PrintMessage("Pick orange triangles"); chosen = ORANGE;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[14];
						pOut->PrintMessage("Pick orange hexagons"); chosen = ORANGE;
					}
				}
				else if (pFig->getGfxInfo().DrawClr == BLUE)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[15];
						pOut->PrintMessage("Pick blue rectangles"); chosen = BLUE;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[16];
						pOut->PrintMessage("Pick blue circles"); chosen = BLUE;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[17];
						pOut->PrintMessage("Pick blue squares"); chosen = BLUE;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[18];
						pOut->PrintMessage("Pick blue triangles"); chosen = BLUE;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[19];
						pOut->PrintMessage("Pick blue hexagons"); chosen = BLUE;
					}
				}
				else if (pFig->getGfxInfo().DrawClr == GREEN)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[20];
						pOut->PrintMessage("Pick green rectangles"); chosen = GREEN;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[21];
						pOut->PrintMessage("Pick green circles"); chosen = GREEN;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[22];
						pOut->PrintMessage("Pick green squares"); chosen = GREEN;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[23];
						pOut->PrintMessage("Pick green triangles"); chosen = GREEN;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[24];
						pOut->PrintMessage("Pick green hexagons"); chosen = GREEN;
					}
				}
				else if (pFig->getGfxInfo().DrawClr == RED)
				{
					if (dynamic_cast<CRectangle*>(pFig))
					{
						Target = Chance[25];
						pOut->PrintMessage("Pick red rectangles"); chosen = RED;
					}
					else if (dynamic_cast<CCirc*>(pFig))
					{
						Target = Chance[26];
						pOut->PrintMessage("Pick red circles"); chosen = RED;
					}
					else if (dynamic_cast<CSquare*>(pFig))
					{
						Target = Chance[27];
						pOut->PrintMessage("Pick red squares"); chosen = RED;
					}
					else if (dynamic_cast<CTriangle*>(pFig))
					{
						Target = Chance[28];
						pOut->PrintMessage("Pick red triangles"); chosen = RED;
					}
					else if (dynamic_cast<CHexagon*>(pFig))
					{
						Target = Chance[29];
						pOut->PrintMessage("Pick red hexagons"); chosen = RED;
					}
				}
			}

			int finTarget = Target; //copied for grading
			while (0 < Target)
			{		CFigure* previous = pManager->getSelectedfig();
		if (previous != NULL && previous->IsSelected() == 1)//If a figure was selected, it is deselected to prevent confusion
		{
			previous->SetSelected(false);
			pManager->setSelectedfig(NULL);
			pManager->UpdateInterface();
		}
				pIn->GetPointClicked(click.x, click.y);
				selectedfig = pManager->GetFigure(click.x, click.y);
				if (click.y > UI.ToolBarHeight || (click.x > (UI.MenuItemWidth * (ITM_TYPECOLOUR + 1)) || click.x < (UI.MenuItemWidth * ITM_TYPECOLOUR)))	//Game is cancelled if icon is selected, then can be restarted
				{
					if (selectedfig != NULL && selectedfig->IsHidden() == false)
					{	
						//Checks if shapes match first. Then, checks if selected figure is filled or not. If filled, FillClr is compared against chosen colour from the randomly chosen figure
						//If unfilled, DrawClr is taken and compared against the randomly chosen color.

						if ((dynamic_cast<CRectangle*>(selectedfig)) && (dynamic_cast<CRectangle*>(pFig)) && ((selectedfig->getGfxInfo().isFilled == true && selectedfig->getGfxInfo().FillClr == chosen) || (selectedfig->getGfxInfo().isFilled == false && selectedfig->getGfxInfo().DrawClr == chosen)))
						{
							Correct++;
							selectedfig->SetHidden(true);
							pManager->UpdateInterface();
							Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
							pOut->PrintMessage(Status);
							Target--;
						}
						else if ((dynamic_cast<CCirc*>(selectedfig)) && (dynamic_cast<CCirc*>(pFig)) && ((selectedfig->getGfxInfo().isFilled == true && selectedfig->getGfxInfo().FillClr == chosen) || (selectedfig->getGfxInfo().isFilled == false && selectedfig->getGfxInfo().DrawClr == chosen)))
						{
							Correct++;
							selectedfig->SetHidden(true);
							pManager->UpdateInterface();
							Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
							pOut->PrintMessage(Status);
							Target--;
						}
						else if ((dynamic_cast<CSquare*>(selectedfig)) && (dynamic_cast<CSquare*>(pFig)) && ((selectedfig->getGfxInfo().isFilled == true && selectedfig->getGfxInfo().FillClr == chosen) || (selectedfig->getGfxInfo().isFilled == false && selectedfig->getGfxInfo().DrawClr == chosen)))
						{
							Correct++;
							selectedfig->SetHidden(true);
							pManager->UpdateInterface();
							Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
							pOut->PrintMessage(Status);
							Target--;
						}
						else if ((dynamic_cast<CTriangle*>(selectedfig)) && (dynamic_cast<CTriangle*>(pFig)) && ((selectedfig->getGfxInfo().isFilled == true && selectedfig->getGfxInfo().FillClr == chosen) || (selectedfig->getGfxInfo().isFilled == false && selectedfig->getGfxInfo().DrawClr == chosen)))
						{
							Correct++;
							selectedfig->SetHidden(true);
							pManager->UpdateInterface();
							Status = "Correct shape selected    Score: " + to_string(Correct) + "    Wrong choice: " + to_string(Incorrect);
							pOut->PrintMessage(Status);
							Target--;
						}
						else if ((dynamic_cast<CHexagon*>(selectedfig)) && (dynamic_cast<CHexagon*>(pFig)) && ((selectedfig->getGfxInfo().isFilled == true && selectedfig->getGfxInfo().FillClr == chosen) || (selectedfig->getGfxInfo().isFilled == false && selectedfig->getGfxInfo().DrawClr == chosen)))
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
					Target = -1; //To prevent game from showing score
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