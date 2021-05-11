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
#include <string>

#include "texteFond.h"

#include "InterfaceGraphiqueButton.h"
#include "InterfaceGraphiqueTexte.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

TexteFond::TexteFond()
{
	m_fondTexte = InterfaceGraphiqueButton();
	m_champTexte = InterfaceGraphiqueTexte("Chanson...");
}

TexteFond::~TexteFond(){}


bool TexteFond::initTexteFond(char *ImgPath)
{
	m_fondTexte.init(ImgPath,"fontplay.png",100,220);
	m_champTexte.initTexte(15);
	return true;
}

	// Destruction de l'interface Graphique
bool TexteFond::destructTexteFond()
{
	m_fondTexte.destruct();
	m_champTexte.destructTexte();
	return true;
}

	// Affiche l'image passée en paramétre aux coordonnés X, Y
bool TexteFond::drawTexteFond(SDL_Surface *fondImage)
{
	m_fondTexte.draw(fondImage);
	m_champTexte.drawTexte(fondImage);
	return true;
}

bool TexteFond::setNomTexte(string nouvNom)
{
	m_sNomChanson = nouvNom;
}
