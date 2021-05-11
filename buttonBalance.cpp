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

#include "buttonBalance.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonBalance::ButtonBalance()
{
	balanceButton = InterfaceGraphiqueButton();
	balanceBarre = InterfaceGraphiqueButton();
}

ButtonBalance::~ButtonBalance(){}

void ButtonBalance::activityBalance(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	SDL_EnableKeyRepeat(20, 20);
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(balanceBarre.isPressedButton(event, balanceBarre.getRectButton(), balanceBarre.getSurfaceButton()))
	{
		balanceButton.setEmplacementY(event->button.y);
	}
}
	// Initialisation de l'interface Graphique
bool ButtonBalance::initButton(char *ImgPath)
{
	balanceBarre.init(ImgPath,"volume_01.png",0,0);
	balanceButton.init(ImgPath,"volumeboutton.png",0,0);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonBalance::destructButton()
{
	balanceButton.destruct();
	balanceBarre.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonBalance::drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa)
{
	balanceBarre.draw(fondImage, nXa, nYa);
	balanceButton.draw(fondImage, nXu, nYu);
	return true;
}

bool ButtonBalance::drawButton(SDL_Surface *fondImage, int nXa, int nYa)
{
	balanceBarre.draw(fondImage, nXa, nYa);
	balanceButton.draw(fondImage,balanceButton.getEmplacementX(),balanceButton.getEmplacementY());
	return true;
}
float ButtonBalance::getBalance()
{
	return (((float)balanceBarre.getTailleHauteur()/(float)balanceButton.getEmplacementY())-1);
}