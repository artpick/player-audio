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

#ifndef INTERFACE_GRAPHIQUE_FOND_H
#define INTERFACE_GRAPHIQUE_FOND_H

#include "InterfaceGraphiqueGeneral.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class InterfaceGraphiqueFond : public virtual InterfaceGraphiqueGeneral
{
private :

	// font d'�cran de l'interface
	SDL_Surface *m_FondEcran;
	SDL_Surface *m_ImgFond;
	
	char *m_pcPathName;
	char *m_pcImgPaint;

	char *m_pcImgPaintIcon;

	SDL_Rect m_pPositionFondEcran;

public :

	// Constructeur, destructeur
	InterfaceGraphiqueFond();
	~InterfaceGraphiqueFond();

	// Initialisation de l'interface Graphique
	virtual bool init(char *pcImgPath, char *pcImgName, int nX, int nY);

	// Destruction de l'interface Graphique
	virtual bool destruct();

	// Affiche l'image pass�e en param�tre aux coordonn�s X, Y
	virtual SDL_Surface * draw(SDL_Surface *fondImage = NULL, int nX = NULL, int nY = NULL);

	//virtual void standExit();

	SDL_Surface *getImgFond();

	bool pathNameGenerate(char *ImgPath, char *imgName);
};

#endif //INTERFACE_GRAPHE_