//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		Étudiant : 
//					[*] Sabos Julian
//					[*] Loïc Zambuto
//
//		Le lecteur media Version Alpha_01
//
//		Description : 
//					Définition des méthodes de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant à l'interface graphique du player
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
		cerr << "Boutton Pause préssé" <<endl;
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

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonPause::drawButton(SDL_Surface *fondImage)
{
	pauseButton.draw(fondImage);
	return true;
}