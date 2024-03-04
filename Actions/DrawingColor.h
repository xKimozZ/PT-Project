#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
class DrawingColor:public Action
{
private:
	ActionType Ctype;
	CFigure* myfig ;
public:
	DrawingColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
};