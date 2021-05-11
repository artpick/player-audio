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

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool drawTexteFond(SDL_Surface *fondImage);

bool setNomTexte(string nouvNom);


};

#endif // TEXTE_FOND