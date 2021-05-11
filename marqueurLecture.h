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

#ifndef BUTTON_MARQUEUR_H
#define BUTTON_MARQUEUR_H

#include "InterfaceGraphiqueButton.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class MarqueurLecture
{
private :

	InterfaceGraphiqueButton marqueurLecture;
	InterfaceGraphiqueButton barreLecture;
	float positionMarqueur;

public :

	// Constructeur, destructeur
MarqueurLecture();
~MarqueurLecture();

	// Initialisation du boutton
bool initButton(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructButton();

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa);

bool drawButton(SDL_Surface *fontImage, int nXa, int nYa);

	// Fonction acc�s etc...
void activityMarqueur(SDL_Event* event);

	// Get Marqueur
float getMarqueurPosition();

// Set Marqueur
bool setMarqueurPosition(float position);

};

#endif //BUTTON_MARQUEUR_