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
	Sprite*                           m_pBackground;
	CharacterSelectionButtonManager   m_buttonManager_1;
	CharacterSelectionButtonManager   m_buttonManager_2;
	Stopwatch                         m_stopwatch;
	Sprite**                          m_pCharacterPortraits_1;
	Sprite**                          m_pCharacterPortraits_2;

	int                               m_iNumPlayers;

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void setUpObjects ();

};

#endif // !GS_CHARACTERSELECT_H
