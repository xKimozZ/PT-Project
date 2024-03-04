#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectOne.h"
#include <fstream>
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "DEFS.h"
#include "GUI\Output.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\DrawingColor.h"
#include "Actions\ChFillColor.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\StartRec.h"
#include "Actions\StopRec.h"
#include "Actions/Action.h"
#include "Actions\PlayRec.h"
#include "Actions\MoveFig.h"
#include "Actions\SwitchToPlay.h"
#include <Windows.h>
#include "Actions\Sound.h"
#include "Actions\ClearAllAction.h"

using namespace std;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	recording=false;
	read = true;
	mute=true;
	canPlay=false;
	isPlaying=false;
	FigCount = 0;
	ActCount = 0;
	SelectedFig=NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	//Create an array of actions pointers and set them to NULL
	for (int i = 0; i < 20; i++)
		RecordList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();	
	
}
void ApplicationManager::PlayAll()
{
	isPlaying=true;
	for (int i = 0;i < ActCount;i++)
	{
		
		SetRead(false);
		RecordList[i]->Execute();
		Sleep(1000);
		UpdateInterface();
	}
	SetRead(true);
	isPlaying=false;
}
void ApplicationManager::AddAction()
{
	if (ActCount < 20)
		RecordList[ActCount++] = LastAction;


}
bool ApplicationManager::GetRec()
{
	return recording;
}
void ApplicationManager::SetRec(bool rec)
{
	recording = rec;
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
bool ApplicationManager::GetRead()
{
	return read ;
}
void ApplicationManager::SetRead(bool Reed)
{
	read = Reed;
}
 void ApplicationManager::SetCanPlay(bool s)
{
	canPlay=s;
}
bool ApplicationManager::GetCanPlay()
{

	return canPlay;
}
int ApplicationManager::getActCount()
{
	return ActCount;
}
void ApplicationManager::setMute(bool s)
{
	mute=s;
}
bool ApplicationManager::getMute()
{
	return mute;
}
void ApplicationManager::setIsplaying(bool s)
{
	isPlaying=s;
}
bool ApplicationManager::getIsPlaying()
{
	return isPlaying;
}
void ApplicationManager::DelFigure(CFigure* pFig)	//Karim function: used to remove pointer to figure in figlist. Figure is deleted from memory in the DeleteFigure action
{
	for (int i = 0; i < FigCount; i++)
	{
		if (pFig->getID() == FigList[i]->getID())	//Checks all IDs in FigList and finds the matching ID of figure to be deleted
		{
			FigList[i] == NULL;						//Remove from figlist
			for (int k = i; k < FigCount - 1; k++)
			{
				FigList[k] = FigList[k + 1];		//Shift all succeeding figures backwards by one place
			}
			FigList[FigCount] = NULL;				//Remove pointer to last figure as it is no longer needed as the previous pointer points to the same figure
			FigCount--;								//Decrease figcount by one
			break;
		}
	}
	SelectedFig = NULL;								//Sets selectedfig pointer in appmanager to null
}

CFigure* ApplicationManager::PlayFigure(int i) const	//Karim function: Sends individual figures to Play mode classes, in order to be able to identify them based on their attributes
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			//if(mute==false) PlaySound(TEXT("Circ.wav"),NULL,SND_SYNC);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			
			break;
		case MENU_SELECT:
			pAct= new SelectOne(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			if(FigCount!=0)
				clearfigs(); // clears figures to prepare for load H
			pAct = new LoadAction(this);
			break;
		case MENU_DRAW:
			pAct = new DrawingColor(this);
			break;
		case FILL:
			pAct = new ChFillColor(this);
			break;
		case STARTREC:
			pAct = new StartRec(this);
			break;
		case STOPREC:
			pAct = new StopRec(this);
			break;
		case MOVE:
			pAct = new MoveFig(this);
			break;
		case PLAYREC :
			pAct = new PlayRec(this);
			break;
		case SOUND:
			pAct= new Sound(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;
		case MENU_DELETE:
			pAct = new DeleteFigure(this);
			break;
		case FILL_COLOURS:
			pAct = new PlayColor(this);
			break;
		case SHAPES:
			pAct = new PlayShape(this);
			break;
		case TYPE_FILL:
			pAct = new PlayBoth(this);
			break;
		case TO_DRAW:
			pAct = new ToDraw(this);
			break;
		case MENU_CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case EXIT1:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		
		//delete pAct;	//You may need to change this line depending to your implementation
		if( ActType!= STARTREC || ActType!= STOPREC || ActType!= PLAYREC  )
		{
			LastAction=pAct;
		}
		pAct->Execute();//Execute
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		
		FigList[FigCount++] = pFig;	
		pFig->setID(FigCount);
}


//Saving Figures saveAll H
void ApplicationManager::saveAll(ofstream &OutFile)
{
	//TO BE DONE: add crnt chosen colors H 25/12
	OutFile<<FigCount<<endl;
	for(int i=0; i<FigCount; i++)
		FigList[i]->Save(OutFile);
}
void ApplicationManager::clearfigs()//clears the figlist H
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	FigCount=0;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	for(int i=FigCount-1;i>=0;i--)
		if(FigList[i]->isInside(x,y) == true)
		{
			return  FigList[i];
		}

	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////
// -- setter and getter for selected fig H
void ApplicationManager::setSelectedfig(CFigure* selected=NULL)
{
		SelectedFig=selected;
	
}
CFigure* ApplicationManager::getSelectedfig()
{
	return SelectedFig;
}
void ApplicationManager::ClearAll()
{
	Output* pOut = GetOutput();
	pOut->ClearDrawArea();
	/*for (int i = 0; i < ActionCount; i++)
	{
		delete UndoList[i];
	}*/
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];

	}
	FigCount = 0;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{               
		if (FigList[i]->IsHidden() == false)
			FigList[i]->Draw(pOut);  //Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < FigCount; i++)
		delete RecordList[i];
	delete pIn;
	delete pOut;
	
}
