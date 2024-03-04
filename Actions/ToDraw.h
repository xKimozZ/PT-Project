#pragma once
#include "Action.h"

class ToDraw : public Action {
public:
	ToDraw(ApplicationManager *pApp);

	//unused
	virtual void ReadActionParameters();

	//switch back to drawmode
	virtual void Execute();
};