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
		cerr << "Boutton Stop préssé" <<endl;
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

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonStop::drawButton(SDL_Surface *fondImage)
{
	stopButton.draw(fondImage);
	return true;
}