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

#include "buttonMute.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonMute::ButtonMute()
{
	muteButton = InterfaceGraphiqueButton();
}

ButtonMute::~ButtonMute(){}

void ButtonMute::activityMute(SDL_Event* event)
{
	if(muteButton.isPressedButton(event, muteButton.getRectButton(), muteButton.getSurfaceButton()))
	{
		cerr << "Boutton Mute préssé" <<endl;
	}
	else{}
}

bool ButtonMute::initButton(char *ImgPath)
{
	muteButton.init(ImgPath, "nosound.png",185, 530);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonMute::destructButton()
{
	muteButton.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonMute::drawButton(SDL_Surface *fondImage)
{
	muteButton.draw(fondImage);
	return true;
}