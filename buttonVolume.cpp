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

#include <iostream>
using namespace std;

#include "buttonVolume.h"
#include "InterfaceGraphiqueButton.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

ButtonVolume::ButtonVolume()
{
	volumeButton = InterfaceGraphiqueButton();
	volumeBarre = InterfaceGraphiqueButton();
}

ButtonVolume::~ButtonVolume(){}

void ButtonVolume::activityVolume(SDL_Event* event)
{
	SDL_EnableKeyRepeat(20, 20);
	//isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface);
	if(volumeBarre.isPressedButton(event, volumeBarre.getRectButton(), volumeBarre.getSurfaceButton()))
	{
		volumeButton.setEmplacementY(event->button.y);
	}
}
bool ButtonVolume::initButton(char *ImgPath)
{
	volumeButton.init(ImgPath,"volumeboutton.png",0,0);
	volumeBarre.init(ImgPath,"volume_01.png",0,0);
	
	return true;
}

	// Destruction de l'interface Graphique
bool ButtonVolume::destructButton()
{
	 volumeButton.destruct();
	return true;
}

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
bool ButtonVolume::drawButton(SDL_Surface *fondImage, int nXu, int nYu, int nXa, int nYa)
{
	volumeBarre.draw(fondImage,nXa, nYa);
	volumeButton.draw(fondImage,nXu,nYu);
	return true;
}

bool ButtonVolume::drawButton(SDL_Surface *fontImage, int nXa, int nYa)
{
	volumeBarre.draw(fontImage, nXa, nYa);
	volumeButton.draw(fontImage,volumeButton.getEmplacementX(),volumeButton.getEmplacementY());
	return true;
}

// fait le rapport entre la taille et la position du boutton, pour retourner le volume.
float ButtonVolume::getVolume()
{
	return (((float)volumeBarre.getTailleHauteur()/(float)volumeButton.getEmplacementY())-1);
}