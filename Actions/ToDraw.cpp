#pragma once
#include "ToDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ToDraw::ToDraw(ApplicationManager *pApp) :Action(pApp)
{
}

void ToDraw::ReadActionParameters()
{}

void ToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Switched to Draw Mode");
}