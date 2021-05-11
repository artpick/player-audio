//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		Étudiant : 
//					[*] Sabos Julian
//					[*] Loïc Zambuto
//
//		Le lecteur media Version Alpha_01
//		Description : 
//					Définition de la classe "interfaceGrapheButton" : Cette classe, permet 
//					d'initialiser les images correspondant à l'interface graphique du player
//
//===========================================================================================================

#ifndef INTERFACE_GRAPHIQUE_BUTTON_H
#define INTERFACE_GRAPHIQUE_BUTTON_H

#include "InterfaceGraphiqueGeneral.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class InterfaceGraphiqueButton : public InterfaceGraphiqueGeneral
{
private :

	//Nom du chemin pour gérer les différentes Skins
	char *m_pcPathName;

	//Nom de la skin du button
	char *m_pcName;
	
	//Emplacement du boutton en X et Y
	int m_iEmplacementX;
	int m_iEmplacementY;

	// Taille du boutton hauteur largeur
	int m_iTailleHauteur;
	int m_iTailleLargeur;

	// Delai entre deux intervales de pression sur le boutton
	int m_iDelai;

	SDL_Surface *m_Button;

	SDL_Rect m_pPositionButton;

public :

	// Constructeur, destructeur
	InterfaceGraphiqueButton();
	InterfaceGraphiqueButton(char *cButtonName);

	~InterfaceGraphiqueButton();

	// Initialisation de l'interface Graphique
	virtual bool init(char *pcImgPath,char *pcImgName, int x, int y);

	// Destruction de l'interface Graphique
	virtual bool destruct();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
	virtual SDL_Surface *draw(SDL_Surface *m_FondEcran);
	virtual SDL_Surface *draw(SDL_Surface *m_FondEcran, int x, int y);
	
	// accésseurs de variables de classe : 
	char *getName();
	char *getPathSkin();

	int getEmplacementX();
	int getEmplacementY();

	void setEmplacementX(int nX);
	void setEmplacementY(int nY);

	int getTailleHauteur();
	int getTailleLargeur();

	int getDelai();

	SDL_Surface* getSurfaceButton();
	SDL_Rect* getRectButton();
	
	bool pathNameGenerate(char *pcImgPath, char *pcImgName);

	bool isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);

};

#endif //INTERFACE_GRAPHIQUE_BUTTON_H