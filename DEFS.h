#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,		//Draw cicle
	DRAW_SQUARE,	//Draw sqaure
	DRAW_TRIANGLE,	//Draw triangle
	DRAW_HEXA,		//Draw hexagon
	MENU_SELECT,	//Select figure
	MENU_DELETE,	//Delete figure
	MENU_CLEAR,		//Clear all
	MENU_UNDO,		//Undo figure
	MENU_REDO,		//Redo figure
	MENU_DRAW,		//Change drawnig color
	STARTREC,		//Start recording
	STOPREC,		//Stop recording
	PLAYREC,		//Play record
	SAVE,			//Save file
	LOAD,			//Load file
	MOVE,			//Move figure
	FILL,			//Fill figure
	C_YELLOW,		//Yellow color
	C_ORANGE,		//Orange color
	C_BLACK,		//Black color
	C_GREEN,		//Green color
	C_BLUE,			//Blue color
	C_RED,			//Red color
	SOUND,			//Play sound or mute it
	TO_PLAY,		//Switch interface to Play mode
	EXIT1,			//Exit icon while in draw mode
	//---------------- Play Mode -------------------//
	FILL_COLOURS,	//Figure Fill Color
	SHAPES,			//Figure type
	TYPE_FILL,		//Figure Type and Fill Color
	EXIT2,			//Exit icon while in play mode
	TO_DRAW,		//Switch interface to Draw mode
	//----------------------------------------------//
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif