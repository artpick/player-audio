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

#include "InterfaceGraphiqueButton.h"



	InterfaceGraphiqueButton::InterfaceGraphiqueButton()
	{
		m_pcPathName = NULL;
		m_pcName = NULL;

		m_iTailleHauteur = 0;
		m_iTailleLargeur = 0;

		m_iDelai = 0;

		m_Button = NULL;
	}

	InterfaceGraphiqueButton::InterfaceGraphiqueButton(char *cButtonName)
	{
		size_t i = strlen(cButtonName);
		strcpy_s(m_pcName,i+1,cButtonName);
		strcat_s(m_pcName,1,'\0');
		
	}

	InterfaceGraphiqueButton::~InterfaceGraphiqueButton()
	{

	}

	// Initialisation de l'interface Graphique
	bool InterfaceGraphiqueButton::init(char *pcImgPath, char *pcImgName, int x, int y)
	{
		// TODO : Revoir la manière de créer des skins différentes
		pathNameGenerate(pcImgPath,pcImgName);
		m_Button = IMG_Load(m_pcPathName);

		m_pPositionButton.x = x;
		m_pPositionButton.y = y;

		if(m_Button != NULL)
		{
			m_iTailleHauteur = m_pPositionButton.y + m_Button->h;
			m_iTailleLargeur = m_pPositionButton.x + m_Button->w;
		}

		return true;
	}

	// Destruction de l'interface Graphique
	bool InterfaceGraphiqueButton::destruct()
	{
		if(m_Button != NULL)
		{
			SDL_FreeSurface(m_Button);
		}
		return true;
	}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
	SDL_Surface *InterfaceGraphiqueButton::draw(SDL_Surface *m_FondEcran, int x, int y)
	{
		m_pPositionButton.x = x;
		m_pPositionButton.y = y;

		if(m_Button != NULL)
		{
			m_iTailleHauteur = m_pPositionButton.y + m_Button->h;
			m_iTailleLargeur = m_pPositionButton.x + m_Button->w;
		}

		SDL_BlitSurface(m_Button, NULL, m_FondEcran, &m_pPositionButton);
		//SDL_Flip(m_FondEcran);
		return m_Button;
	}

	SDL_Surface *InterfaceGraphiqueButton::draw(SDL_Surface *m_FondEcran)
	{
		SDL_BlitSurface(m_Button, NULL, m_FondEcran, &m_pPositionButton);
		//SDL_Flip(m_FondEcran);
		return m_Button;
	}

	// accésseurs de variables de classe : 
	char* InterfaceGraphiqueButton::getName()
	{
		return m_pcName;
	}

	// retourne le chemin de la skin
	char* InterfaceGraphiqueButton::getPathSkin()
	{
		return m_pcPathName;
	}

	int InterfaceGraphiqueButton::getEmplacementX()
	{
		return m_pPositionButton.x;
	};

	int InterfaceGraphiqueButton::getEmplacementY()
	{
		return m_pPositionButton.y;
	};
	void InterfaceGraphiqueButton::setEmplacementX(int nX)
	{
		m_pPositionButton.x = nX;
	};

	void InterfaceGraphiqueButton::setEmplacementY(int nY)
	{
		m_pPositionButton.y = nY;
	};
	int InterfaceGraphiqueButton::getTailleHauteur()
	{
		return m_iTailleHauteur;
	};

	int InterfaceGraphiqueButton::getTailleLargeur()
	{
		return m_iTailleLargeur;
	};

	bool InterfaceGraphiqueButton::pathNameGenerate(char *pcImgPath, char *pcImgName)
	{
		size_t i = strlen(pcImgPath);
		size_t j = strlen(pcImgName);

		m_pcPathName = new char[i+j+1];

		strcpy_s(m_pcPathName,i+1,pcImgPath);

		m_pcName = new char[j+1];

		strcpy_s(m_pcName,j+1,pcImgName);

		strcat_s(m_pcPathName,i+j+1,m_pcName);
		
		return true;
	}
	bool InterfaceGraphiqueButton::isPressedButton(SDL_Event *event, SDL_Rect *position, SDL_Surface *surface)
	{
		if(event->button.x > position->x && event->button.x <  position->x + surface->w 
		&& event->button.y > position->y && event->button.y <  position->y + surface->h)
		{ 
			return true;
		}
		else
		{
			return false;
		}
	}

	SDL_Rect* InterfaceGraphiqueButton::getRectButton()
	{
		return &m_pPositionButton;
	}

	SDL_Surface* InterfaceGraphiqueButton::getSurfaceButton()
	{
		return m_Button;
	}