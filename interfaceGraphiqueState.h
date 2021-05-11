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

#ifndef INTERFACE_GRAPHIQUE_STATE_H
#define INTERFACE_GRAPHIQUE_STATE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class InterfaceGraphiqueState
{
private :

	bool m_bisPlaying;
	bool m_bisPause;

public :

	// Constructeur, destructeur
	InterfaceGraphiqueState() 
	{
		m_bisPlaying = false;
		m_bisPause = false;
	}
	~InterfaceGraphiqueState();

	bool getIsPlaying(){return m_bisPlaying;}
	bool getIsPause(){return m_bisPause;}
	void switchIsPlaying()
	{ 
		if(getIsPlaying())
		{
			m_bisPlaying = false;
		}
		else
		{
			m_bisPlaying = true;
		}
	}

	void switchIsPause()
	{ 
		if(getIsPause())
		{
			m_bisPause = false;
		}
		else
		{
			m_bisPause = true;
		}
	}

};

#endif //INTERFACE_GRAPHIQUE_STATE