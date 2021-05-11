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

#ifndef GENERAL_BUTTON_H
#define GENERAL_BUTTON_H

#include "InterfaceGraphiqueButton.h"
#include "InterfaceGraphiqueFond.h"
#include "InterfaceGraphiqueTexte.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "buttonPlay.h"
#include "buttonStop.h"
#include "buttonPause.h"
#include "buttonMute.h"
#include "buttonNext.h"
#include "buttonRandom.h"
#include "buttonVolume.h"
#include "buttonBalance.h"
#include "buttonVisualisation.h"
#include "buttonRepeat.h"
#include "buttonPrevious.h"

#include "marqueurLecture.h"

class GeneralButton 
{
private :

	// Gestion du temps 
	int m_itempsPrecedent;
	int m_itempsActuel;

	// Image de fond
	InterfaceGraphiqueFond fontPlayer;

	// Déclaration de tous les bouttons : 
	// Bouttons LECTURES
	ButtonPlay play;
	ButtonStop stop;
	ButtonPause pause;
	ButtonNext next;
	ButtonPrevious previous;

	// Bouttons EXTRA
	ButtonRandom random;
	ButtonRepeat repeat;
	ButtonVisualisation visualisation;
	
	// Boutton SON
	ButtonMute mute;
	ButtonVolume volume;
	ButtonBalance balance;

	// Marqueur
	MarqueurLecture marqueur;


	// Texte affiché statiquement dans l'interface
	InterfaceGraphiqueTexte texteTitle;
	InterfaceGraphiqueTexte texteVisualisation;
	InterfaceGraphiqueTexte texteVolume;
	InterfaceGraphiqueTexte texteBalance;
	InterfaceGraphiqueTexte texteVisuOnOff;
	InterfaceGraphiqueTexte texteMute;
	InterfaceGraphiqueTexte textePlayList;
	
	// Image temporaire qui référence le support sur lequel
	// sont déssinés les bouttons
	SDL_Surface *ImgTemp;

	char* m_ptpathSkin;

	bool continuer;

public :

	// Constructeur, destructeur
	GeneralButton();
	~GeneralButton();

	// Initialisation de l'interface Graphique
	bool init();

	// Destruction de l'interface Graphique
	bool destruct();

	// Affiche l'image passée en paramétre aux coordonnés X, Y
	int draw();
	int reDraw();

	int standExit();

	static int GlobalThreadfunc(void* Data)
	{
		GeneralButton *MyThread = reinterpret_cast<GeneralButton*>(Data);
		return MyThread->reDraw();
	}

};

#endif // GENERAL_BUTTON