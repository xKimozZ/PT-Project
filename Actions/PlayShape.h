#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"

//Pick and hide by shape Action class
class PlayShape : public Action
{
private:
	CFigure* pFig;
	Point click;
	int  Target, Incorrect, Correct,Rect,Circ,Square,Tri,Hex;
	string Status;
public:
	PlayShape(ApplicationManager* pApp);

	//Reads all figures' parameters
	virtual void ReadActionParameters();

	//Play sequence
	virtual void Execute();

};