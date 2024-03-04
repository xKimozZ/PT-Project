#include "Action.h"
#include "SaveAction.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include <string>
#include <fstream>
#include "../GUI/UI_Info.h"
SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{

}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Write the name of the file");
	filename=pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void SaveAction::Execute()
{
	ReadActionParameters();
	//string currentchosenDC;
	
	ofstream OutFile(filename+".txt");
	Output* pOut = pManager->GetOutput();
	if(pOut->getCrntDrawColor()== RED)
			OutFile<<"RED"<<endl;
	else if(pOut->getCrntDrawColor()== BLUE)
		OutFile<<"BLUE"<<endl;
	else if(pOut->getCrntDrawColor()== GREEN)
		OutFile<<"GREEN"<<endl;
	else if(pOut->getCrntDrawColor()== YELLOW)
		OutFile<<"YELLOW"<<endl;
	else if(pOut->getCrntDrawColor()== BLACK)
		OutFile<<"BLACK"<<endl;
	else if(pOut->getCrntDrawColor()== ORANGE)
		OutFile<<"ORANGE"<<endl;
	//////////////////////
	if(pOut->getCrntFillColor()==RED)
			OutFile<<"RED"<<endl;
	else if(pOut->getCrntFillColor()== BLUE)
		OutFile<<"BLUE"<<endl;
	else if(pOut->getCrntFillColor()== GREEN)
		OutFile<<"GREEN"<<endl;
	else if(pOut->getCrntFillColor()== YELLOW)
		OutFile<<"YELLOW"<<endl;
	else if(pOut->getCrntFillColor()== BLACK)
		OutFile<<"BLACK"<<endl;
	else if(pOut->getCrntFillColor()== ORANGE)
		OutFile<<"ORANGE"<<endl;
	else 
		OutFile<<"NO_FILL"<<endl;
	pManager->saveAll(OutFile);
	OutFile.close();
	
}