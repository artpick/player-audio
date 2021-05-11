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

#include "buttonRepeat.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonRepeat::ButtonRepeat()
{
	repeatButton = InterfaceGraphiqueButton();
}

ButtonRepeat::~ButtonRepeat(){}

void ButtonRepeat::activityRepeat(SDL_Event* event)
{
	if(repeatButton.isPressedButton(event, repeatButton.getRectButton(), repeatButton.getSurfaceButton()))
	{
		cerr << "Boutton Repeat préssé" <<endl;
	}
}

bool ButtonRepeat::initButton(char *ImgPath)
{
	repeatButton.init(ImgPath,"repeat.png",33,150);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonRepeat::destructButton()
{
	repeatButton.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonRepeat::drawButton(SDL_Surface *fondImage)
{
	repeatButton.draw(fondImage);
	return true;
}