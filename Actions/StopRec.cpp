#include "StopRec.h"

#include "..\ApplicationManager.h"

StopRec::StopRec(ApplicationManager* pApp) :Action(pApp)
{};

//Execute the action
void StopRec::Execute()
{
	if(pManager->GetRec()==true){
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("You Stopped Recording");
		pManager->SetRec(false);
		pManager->SetCanPlay(true);
	}
}
void StopRec::ReadActionParameters()
{
	

}