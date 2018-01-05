/**************************************************************
* | StateMachine Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Handles all of the core game states. Directs their running
* behaviour and handles transitions between them. Links 
* directly with the core game loop.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

///////////////////////////////
// | Headers |
///////////////////////////////

//Includes go here
#include <stdio.h>
#include <cstdint>
#include <SDL.h>
#include "Constants.hpp"
#include "GameStates.hpp"
#include "GS_SplashScreen.hpp"
#include "GS_SplashScreen1.hpp"
#include "GS_VideoIntro.hpp"
#include "GS_StartScreen.hpp"
#include "GS_MainMenu.hpp"
#include "GS_CharacterSelect.hpp"
#include "InputManager.hpp"

class StateMachine
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 StateMachine ( FileLoader* pFileLoader , SDL_Renderer* pRenderer );
	~StateMachine ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	void setNewState ( const eGameState eNewState );

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void init   ( const eGameState eNewState );
	bool update ();

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	GameState*    m_pCurrentState;

	eGameState    m_eStateID;
	eGameState    m_eNewStateID;

	InputManager* m_pInputManager;
	FileLoader*   m_pFileLoader;
	SDL_Renderer* m_pRenderer;

	/////////////

	Uint32 m_uiLastTime;
	Uint32 m_uiElapsedTime;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void changeState  ();
	void cleanupState ();

};

#endif // !STATEMACHINE_H
