/**************************************************************
* | GS_CharacterSelect State |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This class represent the character selection screen. It 
* controls the manipulation of the player cursors to select
* a character within a set time limit.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GS_CHARACTERSELECT_H
#define GS_CHARACTERSELECT_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameState.hpp"
#include "SpriteFactory.hpp"
#include "ControlManager.hpp"
#include "SplashScreenBackground.hpp"
#include "CharacterSelectionButtonManager.hpp"
#include "Stopwatch.hpp"

class GS_CharacterSelect : public GameState
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	         GS_CharacterSelect ( const int iNumPlayers );
	virtual ~GS_CharacterSelect ();

	///////////////////////////////
	// | Property Accessors |
	///////////////////////////////



	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	virtual void enter        () override;
	virtual void handleEvents () override;
	virtual void update       () override;
	virtual void render       () override;
	virtual void exit         () override;


private:

	///////////////////////////////
	// | Variables |
	///////////////////////////////

	SDL_Event                         m_e;
	//Static sprite of screen, slowly to be replaced with dynamic sprites
	Sprite*                           m_pBackground;
	//Buttons managers to take input and control character selection
	CharacterSelectionButtonManager   m_buttonManager_1;
	CharacterSelectionButtonManager   m_buttonManager_2;
	Stopwatch                         m_stopwatch;
	Sprite**                          m_pCharacterSelection;
	//Portrait sprites for selected characters
	Sprite**                          m_pCharacterPortraits_1;
	Sprite**                          m_pCharacterPortraits_2;
	//Sprites for the numbers used by the timer
	Sprite**						  m_pTimerNumbersPool;
	Sprite*							  m_pTimerNumbers_0;
	Sprite*							  m_pTimerNumbers_1;
	//Sprites used for the character's names
	Sprite**						  m_pCharacterNamePool;
	Sprite*							  m_pCharacterName_0;
	Sprite*							  m_pCharacterName_1;
	//Sprites used for small character figures
	Sprite**						  m_pCharacterModelPool;
	Sprite*							  m_pCharacterModel_0;
	Sprite*							  m_pCharacterModel_1;

	int                               m_iNumPlayers;

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void setUpObjects       ();
	void setVisualTimeLeft  ();
	void setCharacterNames  ();
	void setCharacterModels ();
};

#endif // !GS_CHARACTERSELECT_H
