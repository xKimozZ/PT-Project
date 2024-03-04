#pragma once
#include "Action.h"

class SelectOne:public Action
{
private:
	Point click;
public:
	SelectOne(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
};

