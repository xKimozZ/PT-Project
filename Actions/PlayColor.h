#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"

//Pick and hide by color Action class
class PlayColor : public Action
{
private:
	CFigure* pFig;
	color chosen; //color of randomly chosen figure
	Point click;
	int Target, Incorrect, Correct, Black,Yellow,Orange,Blue,Green,Red;
	string Status;
public:
	PlayColor(ApplicationManager* pApp);

	//Reads figures' parameters
	virtual void ReadActionParameters();

	//Play sequence
	virtual void Execute();

};