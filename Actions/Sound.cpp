#include "Sound.h"
#include "../ApplicationManager.h"
 Sound::Sound(ApplicationManager* pApp):Action(pApp)
{

}
void Sound::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(pManager->getMute()==true)
	{
		pManager->setMute(false);
		pOut->PrintMessage("You have unmuted the sound feature");
	}
	else
	{
		pManager->setMute(true);
		pOut->PrintMessage("You have muted the sound feature");
	}
}
void Sound::ReadActionParameters()
{
	

}