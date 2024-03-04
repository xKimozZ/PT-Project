#pragma once
#include "Action.h"
class Sound:public Action
{
public:
	Sound(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
private:

};


