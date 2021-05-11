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

#include "buttonRandom.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonRandom::ButtonRandom()
{
	randomButton = InterfaceGraphiqueButton();
}

ButtonRandom::~ButtonRandom(){}

void ButtonRandom::activityRandom(SDL_Event* event)
{
	if(randomButton.isPressedButton(event, randomButton.getRectButton(), randomButton.getSurfaceButton()))
	{
		cerr << "Boutton Random pr�ss�" <<endl;
	}
}

bool ButtonRandom::initButton(char *ImgPath)
{
	randomButton.init(ImgPath,"rand.png",265,150);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonRandom::destructButton()
{
	randomButton.destruct();
	return true;
}

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool ButtonRandom::drawButton(SDL_Surface *fondImage)
{
	randomButton.draw(fondImage);
	return true;
}