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

#include "InterfaceGraphiqueFond.h"

#include "InterfaceGraphiqueButton.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


	// Constructeur, destructeur
	InterfaceGraphiqueFond::InterfaceGraphiqueFond()
	{
		m_FondEcran = NULL;
		m_ImgFond = NULL;
		
		// TODO : Revoir le systéme de skins, initialiser ici le CHEMIN par rapport a ce qui a été choisis
		// TODO : Initialiser le NOM de l'image

		m_pcImgPaintIcon = "skin\\Alpha_01\\icon.png";
		
		m_pPositionFondEcran.x = 0;
		m_pPositionFondEcran.y = 0;

	}
	InterfaceGraphiqueFond::~InterfaceGraphiqueFond()
	{
	/*	if(m_pcImgPaint != NULL)
			delete []m_pcImgPaint;
		
		if(m_pcPathName != NULL)
			delete []m_pcPathName;*/
	}


	// Initialisation de l'interface Graphique
	bool InterfaceGraphiqueFond::init(char *pcImgPath, char *pcImgName, int nX, int nY)
	{
		if((SDL_Init(SDL_INIT_VIDEO)) == -1)
		{
			//cerr<<"L'erreur suivante est apparue :"<<SDL_GetError()<<'\n';

			exit(EXIT_FAILURE);
		}	

		SDL_WM_SetIcon(IMG_Load(m_pcImgPaintIcon),NULL);

		pathNameGenerate(pcImgPath,pcImgName);

		m_FondEcran = SDL_SetVideoMode(nX ,nY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

		if(m_FondEcran == NULL)
		{
			cerr<<"L'erreur suivante est apparue :"<<SDL_GetError()<<endl;

			exit(EXIT_FAILURE);
		}

		SDL_WM_SetCaption("GrOoOvy Player",NULL);
		
		m_ImgFond = IMG_Load(m_pcPathName);

		return EXIT_SUCCESS;
	}


	// Destruction de l'interface Graphique
	bool InterfaceGraphiqueFond::destruct()
	{
		SDL_FreeSurface(m_ImgFond);
		SDL_FreeSurface(m_FondEcran);

		SDL_Quit();
		return true;
	}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
	
	SDL_Surface *InterfaceGraphiqueFond::draw(SDL_Surface *fondImage, int nX, int nY)
	{
		SDL_BlitSurface(m_ImgFond, NULL, m_FondEcran, &m_pPositionFondEcran);
		
		//SDL_Flip(m_FondEcran);

		return m_FondEcran;
	}

	// Attend que la personne ai appuié sur exit [x]

/*	void InterfaceGraphiqueFond::standExit()
	{
		bool continuer = true;

		SDL_Event event;
		
		while(continuer)
		{
			SDL_WaitEvent(&event);
			switch(event.type)
			{
				case SDL_QUIT : 
					continuer = false;
			}
			
		}
		
	}*/

	SDL_Surface *InterfaceGraphiqueFond::getImgFond()
	{
		return m_ImgFond;
	}

	bool InterfaceGraphiqueFond::pathNameGenerate(char *pcImgPath, char *pcImgName)
	{
		size_t i = strlen(pcImgPath);
		size_t j = strlen(pcImgName);

		m_pcPathName = new char[j+i+1];
		strcpy_s(m_pcPathName,i+1,pcImgPath);
		
		m_pcImgPaint = new char[j+1];
		strcpy_s(m_pcImgPaint,j+1,pcImgName);

		strcat_s(m_pcPathName,i+j+1,m_pcImgPaint);
		
		return true;
	}