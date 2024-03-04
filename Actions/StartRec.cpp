#include "StartRec.h"
#include "..\ApplicationManager.h"

StartRec::StartRec(ApplicationManager* pApp) :Action(pApp)
{};

//Execute the action
void StartRec::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

		if (pManager->GetFigCount() == 0)
		{
			pManager->SetRec(true);
			
			pOut->PrintMessage("You Started Recording");
		}
		else
		{

			pOut->PrintMessage("Recording not available");
		}
		
     
}
void StartRec::ReadActionParameters()
{
}