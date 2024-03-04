#pragma once
#include "Action.h"
#include <string>
class SaveAction:public Action
{
private:
	string filename;
public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};