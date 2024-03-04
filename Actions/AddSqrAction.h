#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point P; //Center of square
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);
	//AddSqrAction();
	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute( );

};

#endif