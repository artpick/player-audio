//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		Étudiant : 
//					[*] Sabos Julian
//					[*] Loïc Zambuto
//
//		Le lecteur media Version Alpha_01
//
//		Description : 
//					Définition des méthodes de la classe "interface" : Cette classe, permet 
//					d'initialiser les images correspondant à l'interface graphique du player
//
//===========================================================================================================

#include <iostream>
using namespace std;

#include "marqueurLecture.h"
#include "InterfaceGraphiqueButton.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

MarqueurLecture::MarqueurLecture()
{
	marqueurLecture = InterfaceGraphiqueButton();
	barreLecture = InterfaceGraphiqueButton();
}

MarqueurLecture::~MarqueurLecture(){}

void MarqueurLecture::activityMarqueur(SDL_Event* event)
{
	SDL_EnableKeyRepeat(20, 20);
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(barreLecture.isPressedButton(event, barreLecture.getRectButton(), barreLecture.getSurfaceButton()))
	{
		marqueurLecture.setEmplacementX(event->button.x);
	}
}
bool MarqueurLecture::initButton(char *ImgPath)
{
	barreLecture.init(ImgPath,"marqueurLecture.png",0,0);
	marqueurLecture.init(ImgPath,"bouttonplay.png",0,0);

	return true;
}

	// Destruction de l'interface Graphique
bool MarqueurLecture::destructButton()
{
	 barreLecture.destruct();
	 marqueurLecture.destruct();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool MarqueurLecture::drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa)
{
	barreLecture.draw(fondImage,nXa, nYa);
	marqueurLecture.draw(fondImage,nXu,nYu);
	return true;
}

bool MarqueurLecture::drawButton(SDL_Surface *fontImage, int nXa, int nYa)
{
	barreLecture.draw(fontImage, nXa, nYa);
	marqueurLecture.draw(fontImage,marqueurLecture.getEmplacementX(),marqueurLecture.getEmplacementY());
	return true;
}

// fait le rapport entre la taille et la position du boutton, pour retourner le MarqueurLecture.
float MarqueurLecture::getMarqueurPosition()
{
	return (((float)barreLecture.getTailleHauteur()/(float)marqueurLecture.getEmplacementY())-1);
}

// positionne le curseur au bonne endroit sur la barre de lecture
bool MarqueurLecture::setMarqueurPosition(float position)
{
	float valFloatTemp;
	int valIntTemp;

	valFloatTemp = (position);
	valIntTemp = (int)(valFloatTemp * ((float)barreLecture.getTailleLargeur()));

	marqueurLecture.setEmplacementX(barreLecture.getEmplacementX() + valIntTemp);

	return true;
}