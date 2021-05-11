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

#include "buttonPlay.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonPlay::ButtonPlay()
{
	playButton = InterfaceGraphiqueButton();
}

ButtonPlay::~ButtonPlay(){}

void ButtonPlay::activityPlay(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(playButton.isPressedButton(event, playButton.getRectButton(), playButton.getSurfaceButton()))
	{
		cerr << "Boutton Play préssé" << endl;
	}
}
bool ButtonPlay::initButton(char *ImgPath)
{
	playButton.init(ImgPath,"play.png",170,220);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonPlay::destructButton()
{
	playButton.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonPlay::drawButton(SDL_Surface *fondImage)
{
	playButton.draw(fondImage);
	return true;
}