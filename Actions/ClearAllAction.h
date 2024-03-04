#pragma once
#include "Action.h"
#include"../ApplicationManager.h"
#include"ChFillColor.h"
class ClearAllAction :public Action
{
private:
	ActionType* ClearAct;
public:
	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
};