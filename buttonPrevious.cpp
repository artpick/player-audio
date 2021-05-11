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

#include "buttonPrevious.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonPrevious::ButtonPrevious()
{
	previousButton = InterfaceGraphiqueButton();
}

ButtonPrevious::~ButtonPrevious(){}

void ButtonPrevious::activityPrevious(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(previousButton.isPressedButton(event, previousButton.getRectButton(), previousButton.getSurfaceButton()))
	{
		cerr << "Boutton Previous préssé" <<endl;
	}
	else
	{}
}

bool ButtonPrevious::initButton(char *ImgPath)
{
	previousButton.init(ImgPath,"previous.png",30,220);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonPrevious::destructButton()
{
	previousButton.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonPrevious::drawButton(SDL_Surface *fondImage)
{
	previousButton.draw(fondImage);
	return true;
}