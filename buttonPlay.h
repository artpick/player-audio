//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		?tudiant : 
//					[*] Sabos Julian
//					[*] Lo?c Zambuto
//
//		Le lecteur media Version Alpha_01
//		Description : 
//					D?finition de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant ? l'interface graphique du player
//
//===========================================================================================================

#ifndef BUTTON_PLAY_H
#define BUTTON_PLAY_H

#include "InterfaceGraphiqueButton.h"
// #include "<Avtivit? de lire une chanson>"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ButtonPlay
{
private :

	InterfaceGraphiqueButton playButton;

public :

	// Constructeur, destructeur
ButtonPlay();
~ButtonPlay();

		// Initialisation du boutton
bool initButton(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructButton();

	// Affiche l'image pass?e en param?tre aux coordonn?s X, Y
bool drawButton(SDL_Surface *fondImage);

	// Fonction acc?s etc...
void activityPlay(SDL_Event* event);
};

#endif //INTERFACE_GRAPHE_