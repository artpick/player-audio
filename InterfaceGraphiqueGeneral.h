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

#ifndef INTERFACE_GRAPHIQUE_GENERAL_H
#define INTERFACE_GRAPHIQUE_GENERAL_H

#include <SDL/SDL.h>


#include <string>

using namespace std;

class InterfaceGraphiqueGeneral
{
	// Initialisation de l'interface Graphique
	virtual bool init(char *pcImgPath = NULL,char *pcImgName = NULL, int x = NULL, int y = NULL) = 0;

	// Destruction de l'interface Graphique
	virtual bool destruct() = 0;

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
	virtual SDL_Surface *draw(SDL_Surface *m_FondEcran = NULL, int x = 0, int y = 0) = 0;
};
#endif