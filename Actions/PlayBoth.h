#pragma once

#include "Action.h"
#include "../Figures/CFigure.h"

//Pick and hide both Action class
class PlayBoth : public Action
{
private:
	CFigure* pFig;
	Point click;
	color chosen; //randomly picked object's color
	int  Number, Target, Incorrect, Correct;
	int	 Chance[30]; //30 different possibilities (unfilled and filled figures and colors taken into consideration)
	string Status;
public:
	PlayBoth(ApplicationManager* pApp);

	//Reads figures' parameters
	virtual void ReadActionParameters();

	//Play sequence
	virtual void Execute();

};