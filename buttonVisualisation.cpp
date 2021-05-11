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

#include "buttonVisualisation.h"
#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

ButtonVisualisation::ButtonVisualisation()
{
	visualisationButton = InterfaceGraphiqueButton();
}

ButtonVisualisation::~ButtonVisualisation(){}

void ButtonVisualisation::activityVisualisation(SDL_Event* event)
{
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(visualisationButton.isPressedButton(event, visualisationButton.getRectButton(), visualisationButton.getSurfaceButton()))
	{
		cerr << "Boutton Visualisation préssé" <<endl;
	}
	else{}
}
bool ButtonVisualisation::initButton(char *ImgPath)
{
	visualisationButton.init(ImgPath,"visu.png",60,530);
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonVisualisation::destructButton()
{
	 visualisationButton.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool ButtonVisualisation::drawButton(SDL_Surface *fondImage)
{
	visualisationButton.draw(fondImage);
	return true;
}