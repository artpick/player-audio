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

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "generalButton.h"

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

#include "InterfaceGraphiqueTexte.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

GeneralButton::GeneralButton()
{
	/*	bouttonplayButton.init("skin\\Alpha_01\\","bouttonplay.png",0,0);
	bouttonplayButton.draw(ImgTemp,30,100);*/

	// TODO : Recherche le chemin du la skin ICI
	size_t i = strlen("skin\\Alpha_01\\");
	m_ptpathSkin = new char[i+1];
	strcpy_s(m_ptpathSkin,i+1,"skin\\Alpha_01\\");
	
	// Fin recherche PATH-SKIN

	ImgTemp = NULL;
	fontPlayer = InterfaceGraphiqueFond();

	// Initialisation du texte : affichages/ 
	texteTitle = InterfaceGraphiqueTexte("GrOoOvY Player");
	texteVisualisation = InterfaceGraphiqueTexte("Visualisation");
	texteVolume = InterfaceGraphiqueTexte("Volume");
	texteBalance = InterfaceGraphiqueTexte("Balance");
	texteVisuOnOff = InterfaceGraphiqueTexte("Visualisation On Off");
	texteMute = InterfaceGraphiqueTexte("Mute");
	textePlayList = InterfaceGraphiqueTexte("PlayList");

	// Player
	play = ButtonPlay();
	stop = ButtonStop();
	pause = ButtonPause();
	next = ButtonNext();
	previous = ButtonPrevious();

	// Bouttons EXTRA
	random = ButtonRandom();
	repeat = ButtonRepeat();
	visualisation = ButtonVisualisation();
	
	// Boutton SON
	mute = ButtonMute();
	volume = ButtonVolume();
	balance = ButtonBalance();

	marqueur = MarqueurLecture();
	
	m_itempsPrecedent = 0;
	m_itempsActuel = 0;
	
}

GeneralButton::~GeneralButton(){}


int GeneralButton::standExit()
{
	continuer = true;
	
	SDL_Event event;
	
	while(continuer)
	{
		SDL_PollEvent(&event);
		
		switch(event.type)
		{
			
			case SDL_QUIT : 
				continuer = false;
				break;
		
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
					case SDL_BUTTON_LEFT : 
						// activité de LECTURE
						play.activityPlay(&event);
						pause.activityPause(&event);
						stop.activityStop(&event);
						previous.activityPrevious(&event);
						next.activityNext(&event);
						
						// activité EXTRA
						random.activityRandom(&event);
						repeat.activityRepeat(&event);
						visualisation.activityVisualisation(&event);

						// activité VOLUME
						volume.activityVolume(&event);
						balance.activityBalance(&event);
						mute.activityMute(&event);
						marqueur.activityMarqueur(&event);

						break;

					default : 
						cerr << "Pas de bouttons" << endl;
					
				}
				break;
		}

	/*	m_itempsActuel = SDL_GetTicks();

		if(m_itempsActuel - m_itempsPrecedent > 30)
		{
			//this->draw();
			this->reDraw();
			m_itempsPrecedent = m_itempsActuel;
		}
		else
		{
			SDL_Delay(30 - (m_itempsActuel - m_itempsPrecedent));
		}
		*/
		
	}
	// cerr << "fin de standExit" << endl;
	return 1;
}



bool GeneralButton::init()
{
	fontPlayer.init(m_ptpathSkin,"imageFond.png",800, 600);
	play.initButton(m_ptpathSkin);
	stop.initButton(m_ptpathSkin);
	pause.initButton(m_ptpathSkin);
	next.initButton(m_ptpathSkin);
	previous.initButton(m_ptpathSkin);

	// Bouttons EXTRA
	random.initButton(m_ptpathSkin);
	repeat.initButton(m_ptpathSkin);
	visualisation.initButton(m_ptpathSkin);
	
	// Boutton SON
	mute.initButton(m_ptpathSkin);
	volume.initButton(m_ptpathSkin);
	balance.initButton(m_ptpathSkin);

	// Boutton Marqueur
	marqueur.initButton(m_ptpathSkin);

	// Texte Init
	texteTitle.initTexte(20);
	texteVisualisation.initTexte(15);
	texteVolume.initTexte(15);
	texteBalance.initTexte(15);
	texteVisuOnOff.initTexte(15);
	texteMute.initTexte(15);
	textePlayList.initTexte(20);

	// Initialisation du timer
	

	return true;
}

int GeneralButton::draw()
{
	ImgTemp = fontPlayer.draw();

	play.drawButton(ImgTemp);
	stop.drawButton(ImgTemp);
	pause.drawButton(ImgTemp);
	next.drawButton(ImgTemp);
	previous.drawButton(ImgTemp);

	// Bouttons EXTRA
	random.drawButton(ImgTemp);
	repeat.drawButton(ImgTemp);
	visualisation.drawButton(ImgTemp);
	
	// Boutton SON
	mute.drawButton(ImgTemp);
	volume.drawButton(ImgTemp, 270, 530, 280, 330);
	balance.drawButton(ImgTemp,340,530, 350, 330);

	// Marqueur lecture
	marqueur.drawButton(ImgTemp,20,135,20,130);

	// Texte
	texteTitle.drawTexte(ImgTemp, 12, 9);
	texteVisualisation.drawTexte(ImgTemp, 12, 295);
	texteVolume.drawTexte(ImgTemp, 270, 295);
	texteBalance.drawTexte(ImgTemp, 335, 295);
	texteVisuOnOff.drawTexte(ImgTemp, 12, 580);
	texteMute.drawTexte(ImgTemp, 190, 580);
	textePlayList.drawTexte(ImgTemp, 450, 9);
	
	SDL_Flip(ImgTemp);

	return 1;
}

bool GeneralButton::destruct()
{
	play.destructButton();
	stop.destructButton();
	pause.destructButton();
	next.destructButton();
	previous.destructButton();

	// Bouttons EXTRA
	random.destructButton();
	repeat.destructButton();
	visualisation.destructButton();
	
	// Boutton SON
	mute.destructButton();
	volume.destructButton();
	balance.destructButton();
	
	// Marqueur Lecture
	marqueur.destructButton();

	// Texte Desctruction
	texteTitle.destructTexte();
	texteVisualisation.destructTexte();
	texteVolume.destructTexte();
	texteBalance.destructTexte();
	texteVisuOnOff.destructTexte();
	texteMute.destructTexte();
	textePlayList.destructTexte();

	SDL_FreeSurface(ImgTemp);
	return true;
}



int GeneralButton::reDraw()
{
	while(continuer)
	{
		fontPlayer.draw();

		play.drawButton(ImgTemp);
		stop.drawButton(ImgTemp);
		pause.drawButton(ImgTemp);
		next.drawButton(ImgTemp);
		previous.drawButton(ImgTemp);

		// Bouttons EXTRA
		random.drawButton(ImgTemp);
		repeat.drawButton(ImgTemp);
		visualisation.drawButton(ImgTemp);
		
		// Boutton SON
		mute.drawButton(ImgTemp);
		volume.drawButton(ImgTemp,280, 330);
		balance.drawButton(ImgTemp,350, 330);

		// Marqueur lecture
		marqueur.drawButton(ImgTemp,20,130);

		// Texte
		texteTitle.drawTexte(ImgTemp, 12, 9);
		texteVisualisation.drawTexte(ImgTemp, 12, 295);
		texteVolume.drawTexte(ImgTemp, 270, 295);
		texteBalance.drawTexte(ImgTemp, 335, 295);
		texteVisuOnOff.drawTexte(ImgTemp, 12, 580);
		texteMute.drawTexte(ImgTemp, 190, 580);
		textePlayList.drawTexte(ImgTemp, 450, 9);
		
		SDL_Flip(ImgTemp);
		SDL_Delay(1000);
		cerr << "fin de reDraw" << endl;
	}
	return 1;
}