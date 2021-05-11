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

#ifndef INTERFACE_GRAPHIQUE_TEXTE_H
#define INTERFACE_GRAPHIQUE_TEXTE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

class InterfaceGraphiqueTexte 
{
private :

	// font d'écran de l'interface
	SDL_Rect m_ptpositionTexte;
	TTF_Font *m_ptpoliceFont;
	SDL_Color m_ptcolorTexte;
	SDL_Surface *m_ptTexte;
	char *m_cpttexteAffiche;

public :

	// Constructeur, destructeur
	InterfaceGraphiqueTexte();
	InterfaceGraphiqueTexte(char *texteEntre);
	~InterfaceGraphiqueTexte();

	// Initialisation de l'interface Graphique
	bool initTexte(int sizeFont);

	// Destruction de l'interface Graphique
	bool destructTexte();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
	bool drawTexte(SDL_Surface *fondImage = NULL, int nX = NULL, int nY = NULL);

};

#endif //INTERFACE_GRAPHE_TEXTE