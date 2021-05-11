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

#ifndef BUTTON_BALANCE_H
#define BUTTON_BALANCE_H

#include "InterfaceGraphiqueButton.h"
#include "InterfaceGraphiqueGeneral.h"
// #include "<Avtivité de lire une chanson>"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ButtonBalance 
{
private :

	InterfaceGraphiqueButton balanceButton;
	InterfaceGraphiqueButton balanceBarre;

public :

	// Constructeur, destructeur
ButtonBalance();
~ButtonBalance();

bool initButton(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructButton();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool drawButton(SDL_Surface *fondImage, int nX, int nY);
bool drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa);

	// Fonction accés etc...
void activityBalance(SDL_Event* event);

float getBalance();


};

#endif //BUTTON_BALANCE