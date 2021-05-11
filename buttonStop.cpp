//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		�tudiant : 
//					[*] Sabos Julian
//					[*] Lo�c Zambuto
//
//		Le lecteur media Version Alpha_01
//
//		Description : 
//					D�finition des m�thodes de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant � l'interface graphique du player
//
//===========================================================================================================

#include <iostream>
using namespace std;

#include "buttonStop.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonStop::ButtonStop()
{
	stopButton = InterfaceGraphiqueButton();
}

ButtonStop::~ButtonStop(){}

void ButtonStop::activityStop(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(stopButton.isPressedButton(event, stopButton.getRectButton(), stopButton.getSurfaceButton()))
	{
		cerr << "Boutton Stop pr�ss�" <<endl;
	}
	else{}
}

bool ButtonStop::initButton(char *ImgPath)
{
	stopButton.init(ImgPath,"stop.png",100,220);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonStop::destructButton()
{
	 stopButton.destruct();
	return true;
}

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool ButtonStop::drawButton(SDL_Surface *fondImage)
{
	stopButton.draw(fondImage);
	return true;
}