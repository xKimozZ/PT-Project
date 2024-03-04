#include "PlayRec.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"

PlayRec::PlayRec(ApplicationManager* pApp) :Action(pApp)
{};

//Execute the action
void PlayRec::Execute()
{
	if(pManager->getActCount()>0 && pManager->GetCanPlay()==true)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Playing record now");
		ReadActionParameters();
		pManager->SetRead(false);

		pOut->ClearDrawArea();

		pManager->clearfigs();

		pManager->PlayAll();
	}
}
void PlayRec::ReadActionParameters()
{
	

}