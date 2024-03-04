#pragma once
#include "Action.h"
class StopRec :public Action
{
private:

public:
	StopRec(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};
