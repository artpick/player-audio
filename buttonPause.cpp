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

#include "buttonPause.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonPause::ButtonPause()
{
	pauseButton = InterfaceGraphiqueButton();
}


ButtonPause::~ButtonPause(){}

void ButtonPause::activityPause(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(pauseButton.isPressedButton(event, pauseButton.getRectButton(), pauseButton.getSurfaceButton()))
	{
		cerr << "Boutton Pause pr�ss�" <<endl;
	}
	else{}
}


bool ButtonPause::initButton(char *ImgPath)
{
	pauseButton.init(ImgPath,"pause.png",240,220);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonPause::destructButton()
{
	pauseButton.destruct();
	return true;
}

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool ButtonPause::drawButton(SDL_Surface *fondImage)
{
	pauseButton.draw(fondImage);
	return true;
}