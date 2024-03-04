#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include"..\Figures\CSquare.h"

class MoveFig :public Action
{
private:
	 
	Point P;
	CFigure* myFig;
	 
public:

	MoveFig(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};