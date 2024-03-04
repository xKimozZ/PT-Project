#pragma once

#include "Action.h"
class StartRec:public Action
{
private:

public:
	StartRec(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};
