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

#include "InterfaceGraphiqueTexte.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

// Constructeur, destructeur

InterfaceGraphiqueTexte::InterfaceGraphiqueTexte()
{
	m_ptcolorTexte.b = 0;
	m_ptcolorTexte.g = 255;
	m_ptcolorTexte.r = 0;
}
InterfaceGraphiqueTexte::InterfaceGraphiqueTexte(char *texteEntre)
{
	size_t i = strlen(texteEntre);
	m_cpttexteAffiche = new char[i+1];
	strcpy_s(m_cpttexteAffiche,i+1,texteEntre);
	m_ptcolorTexte.b = 254;
	m_ptcolorTexte.g = 254;
	m_ptcolorTexte.r = 254;
}

InterfaceGraphiqueTexte::~InterfaceGraphiqueTexte()
{}

bool InterfaceGraphiqueTexte::initTexte(int sizeFont)
{
	if(TTF_Init()== -1)
	{
		cerr<<"L'erreur suivante est apparue :"<<TTF_GetError()<<endl;
		exit(EXIT_FAILURE);
	}
	
	m_ptpoliceFont = TTF_OpenFont("arial.ttf",sizeFont);
	
	TTF_SetFontStyle(m_ptpoliceFont,TTF_STYLE_BOLD);
	
	m_ptTexte = TTF_RenderText_Blended(m_ptpoliceFont, m_cpttexteAffiche, m_ptcolorTexte);
	
	return true;
}

bool InterfaceGraphiqueTexte::drawTexte(SDL_Surface *fondImage, int nX, int nY)
{

	m_ptpositionTexte.x = nX;
	m_ptpositionTexte.y = nY;
	
	SDL_BlitSurface(m_ptTexte, NULL, fondImage, &m_ptpositionTexte);
	//SDL_Flip(fondImage);
	
	return true;
}

bool InterfaceGraphiqueTexte::destructTexte()
{
	TTF_CloseFont(m_ptpoliceFont);
	TTF_Quit();

	return true;
}