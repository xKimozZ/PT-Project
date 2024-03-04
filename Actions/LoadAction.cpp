#include "LoadAction.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include <fstream>
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CCirc.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CHexagon.h"
LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{

}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Write the name of the file, you want to load from");
	filename=pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream Infile(filename + ".txt");
	CFigure* myfig=NULL;
	Infile>>crntdraw;
	Infile>>crntfill;
	Infile>>noFigs;
	pOut->setCrntDrawColor(crntdraw);
	pOut->setCrntFillColor(crntfill);
	for(int i=0;i<noFigs;i++)
	{
		Infile>>type;
		if (type=="RECT")
		{
			myfig=new CRectangle;
		}
		else if(type=="SQR")
		{
			myfig = new CSquare;
		}
		else if(type=="CIRC")
		{
			myfig = new CCirc;
		}
		else if(type == "HEX")
		{
			myfig = new CHexagon;
		}
		else if(type == "TRI")
		{
			myfig = new CTriangle;
		}
		myfig->Load(Infile);
		
		pManager->AddFigure(myfig);

	}
}