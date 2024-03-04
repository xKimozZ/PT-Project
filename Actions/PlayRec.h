#pragma once
#include "Action.h"

class PlayRec :public Action
{
private:

public:
	PlayRec(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};