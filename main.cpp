#include "ApplicationManager.h"
//#include <fstream>

int main()
{
	/*ofstream Outf("ggg.txt");
	Outf<<"hi"<<endl;
	Outf.close();*/
	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while(ActType != EXIT1);
	

	
	return 0;
}

