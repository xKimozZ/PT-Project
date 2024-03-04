#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "GUI\output.h"
#include "Actions/StartRec.h"
#include "Actions/Action.h"
#include "Actions\DeleteFigure.h"
#include "Actions\PlayShape.h"
#include "Actions\PlayColor.h"
#include "Actions\PlayBoth.h"
#include "Actions\ToDraw.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action* LastAction; //Pointer to the last action exicuted
	CFigure* SelectedFig; //Pointer to the selected figure
	Action* RecordList[20]; //List of all actions (Array of pointers)
	bool recording;
	bool read;
	bool canPlay;//allows u to play rec
	bool mute;//mutes the voice
	bool isPlaying;//is playing record so it doesnt play the voice
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int ActCount ;

	
public:	
	ApplicationManager(); 
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	Action* GetLastAction();

	// -- Actions Management Functions
	void AddAction();  // Adds a new action to the Recordlist
	void PlayAll();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DelFigure(CFigure* pFig);          //Removes figure from FigList and rearranges the list
	CFigure* PlayFigure(int i) const;		//Gets individual figure from figlist in order to prepare play mode
	// -- setter and getter for selected fig H
	void setSelectedfig(CFigure* selected);//set fig 
	CFigure* getSelectedfig();// get fig


	//-- Deleting figs in figlist for the loadAction H
	void clearfigs(); // clear figs H
	void saveAll(ofstream &OutFile);//saves figs in a txt file H


	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	// -- 
	void SetRec(bool rec); 
	bool GetRec();
	int GetFigCount();
	void SetRead(bool Reed);
	bool GetRead();
	void SetCanPlay(bool s);//et if i can play rec
	bool GetCanPlay();//get if i can play rec
	int getActCount();
	void setMute(bool s);
	bool getMute();
	void setIsplaying(bool s);
	bool getIsPlaying();
	void ClearAll();
};

#endif