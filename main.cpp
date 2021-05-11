//===========================================================================================================
//		Projet Licence 3 Informatique Valenciennes 
//		Étudiant : 
//					[*] Sabos Julian
//					[*] Loïc Zambuto
//
//		Le lecteur media Version Alpha_01
//
//===========================================================================================================

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


#include "generalButton.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_thread.h"

int main(int argc, char *argv[])
{
	SDL_Thread* thread;

	GeneralButton m_generalButton = GeneralButton();

	m_generalButton.init();

	m_generalButton.draw();

	thread = SDL_CreateThread(&GeneralButton::GlobalThreadfunc,&m_generalButton); //

	m_generalButton.standExit();

	m_generalButton.destruct();

	return EXIT_SUCCESS; // Fermeture du programme
}