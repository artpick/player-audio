//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		Étudiant : 
//					[*] Sabos Julian
//					[*] Loïc Zambuto
//
//		Le lecteur media Version Alpha_01
//		Description : 
//					Définition de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant à l'interface graphique du player
//
//===========================================================================================================

#ifndef BUTTON_VOLUME_H
#define BUTTON_VOLUME_H

#include "InterfaceGraphiqueButton.h"
// #include "<Avtivité de lire une chanson>"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ButtonVolume
{
private :

	InterfaceGraphiqueButton volumeButton;
	InterfaceGraphiqueButton volumeBarre;

public :

	// Constructeur, destructeur
ButtonVolume();
~ButtonVolume();

	// Initialisation du boutton
bool initButton(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructButton();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa);

bool drawButton(SDL_Surface *fontImage, int nXa, int nYa);

	// Fonction accés etc...
void activityVolume(SDL_Event* event);

	// Get volume
float getVolume();
};

#endif //BUTTON_VOLUME