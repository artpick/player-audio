//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		�tudiant : 
//					[*] Sabos Julian
//					[*] Lo�c Zambuto
//
//		Le lecteur media Version Alpha_01
//		Description : 
//					D�finition de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant � l'interface graphique du player
//
//===========================================================================================================

#ifndef BUTTON_BALANCE_H
#define BUTTON_BALANCE_H

#include "InterfaceGraphiqueButton.h"
#include "InterfaceGraphiqueGeneral.h"
// #include "<Avtivit� de lire une chanson>"

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

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool drawButton(SDL_Surface *fondImage, int nX, int nY);
bool drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa);

	// Fonction acc�s etc...
void activityBalance(SDL_Event* event);

float getBalance();


};

#endif //BUTTON_BALANCE