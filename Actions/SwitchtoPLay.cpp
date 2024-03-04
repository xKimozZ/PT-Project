#include "SwitchToPlay.h"

#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{};

//Execute the action
void SwitchToPlay::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() < 2)
		pOut->PrintMessage("At least 2 figures needed to play");
	else
	{
		pOut->CreatePlayToolBar();
		UI.InterfaceMode = MODE_PLAY;
		ReadActionParameters();
	}
}
void SwitchToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You switched to play mode");
}