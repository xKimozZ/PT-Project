#pragma once
#include "Action.h"
class LoadAction:public Action
{
	private:
		string filename;
		string type;
		string crntdraw;
		string crntfill;
		int noFigs;

	public:
		LoadAction(ApplicationManager *pApp);
		virtual void ReadActionParameters();
		virtual void Execute(); 
};

