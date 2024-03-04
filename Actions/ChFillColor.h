#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class ChFillColor:public Action
{
private:
	ActionType Ctype;
	CFigure* myfig;
public:
	ChFillColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

