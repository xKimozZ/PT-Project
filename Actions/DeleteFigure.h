#pragma once

#include"Action.h"
#include "../Figures/CFigure.h"

//Delete Figure Action class
class DeleteFigure : public Action
{
private:
	CFigure* marked;
public:
	DeleteFigure(ApplicationManager* pApp);

	//unused here
	virtual void ReadActionParameters();

	//Deletes figure from memory
	virtual void Execute();

};