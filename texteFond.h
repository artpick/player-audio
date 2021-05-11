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

#ifndef TEXTE_FOND_H
#define TEXTE_FOND_H

#include "InterfaceGraphiqueButton.h"
#include "InterfaceGraphiqueTexte.h"

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"



class TexteFond 
{
private :
	
	//Nom de la chanson
	string m_sNomChanson;
	InterfaceGraphiqueButton m_fondTexte;
	InterfaceGraphiqueTexte m_champTexte ;
public :

	// Constructeur, destructeur
	TexteFond();
	~TexteFond();

	// Initialisation du boutton
bool initTexteFond(char *ImgPath);

	// Destruction de l'interface Graphique
bool destructTexteFond();

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool drawTexteFond(SDL_Surface *fondImage);

bool setNomTexte(string nouvNom);


};

#endif // TEXTE_FOND