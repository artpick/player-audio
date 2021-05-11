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

#include "buttonNext.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonNext::ButtonNext()
{
	nextButton = InterfaceGraphiqueButton();
}

ButtonNext::~ButtonNext(){}

void ButtonNext::activityNext(SDL_Event* event)
{
	if(nextButton.isPressedButton(event, nextButton.getRectButton(), nextButton.getSurfaceButton()))
	{
		cerr << "Boutton Next pr�ss�" <<endl;
	}
	else{}
}

bool ButtonNext::initButton(char *ImgPath)
{
	nextButton.init(ImgPath,"next.png",310,220);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonNext::destructButton()
{
	nextButton.destruct();
	return true;
}

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool ButtonNext::drawButton(SDL_Surface *fondImage)
{
	nextButton.draw(fondImage);
	return true;
}