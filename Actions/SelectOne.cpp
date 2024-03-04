#include "SelectOne.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "Action.h"
SelectOne::SelectOne(ApplicationManager *pApp):Action(pApp)
{
}
void SelectOne::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose a figure to select");
	pIn->GetPointClicked(click.x,click.y);
	pOut->ClearStatusBar();
}
void SelectOne::Execute()
{

	if (pManager->GetRead() == true)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	Output* pOut = pManager->GetOutput();
	CFigure* previous= pManager->getSelectedfig();
	
	if(previous!=NULL && previous->IsSelected()==1 && pManager->GetFigure(click.x,click.y))//previous figure check if it was selected and deselects it 
	{
		previous->SetSelected(false);
	}
	
	CFigure* selectedfig=pManager->GetFigure(click.x,click.y);//the new selected fig
	

	if(selectedfig != NULL &&( selectedfig->IsSelected())==0  )//if that fig isnt selected
		{
			pManager->setSelectedfig(selectedfig);//select it and set it in manager
			if(selectedfig!=previous)//if that fig isnt selected and its not the previous fig
			{
				
				selectedfig->SetSelected(true);
				selectedfig->PrintInfo(pOut);
			}
			else if(selectedfig==previous)//if that fig isnt selected and its the previous fig
			{	
				pManager->setSelectedfig(NULL);
			}			
		}
	if (pManager->GetRec() == true)
	{
		pManager->AddAction();
	}
}


