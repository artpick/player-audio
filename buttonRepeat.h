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

#ifndef BUTTON_REPEAT_H
#define BUTTON_REPEAT_H

#include "InterfaceGraphiqueButton.h"
// #include "<Avtivité de lire une chanson>"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ButtonRepeat
{
private :

	InterfaceGraphiqueButton repeatButton;

public :

	// Constructeur, destructeur
ButtonRepeat();
~ButtonRepeat();

	// Initialisation du boutton
bool initButton(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructButton();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool drawButton(SDL_Surface *fondImage);

	// Fonction accés etc...
void activityRepeat(SDL_Event* event);
};

#endif //BUTTON_REPEAT