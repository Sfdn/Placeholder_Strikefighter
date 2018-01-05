#include "StateMachine.hpp"

StateMachine::StateMachine ( FileLoader* pFileLoader , SDL_Renderer* pRenderer )
	: m_pCurrentState  ( nullptr					)
	, m_eStateID       ( eGameState::GAMESTATE_NULL )
	, m_eNewStateID    ( eGameState::GAMESTATE_NULL )
	, m_pInputManager  ( new InputManager           )
	, m_pFileLoader    ( pFileLoader                )
	, m_pRenderer      ( pRenderer                  )
	, m_uiLastTime     ( SDL_GetTicks ()		    )
	, m_uiElapsedTime  ( 0						    )
{
}

StateMachine::~StateMachine ()
{
	//Delete the current state.
	cleanupState ();
}

void StateMachine::setNewState ( const eGameState iNewState )
{
	//Update the new state ID.
	m_eNewStateID = iNewState;
}

void StateMachine::init ( const eGameState eNewState )
{
	setNewState ( eNewState );
	changeState ();
}

bool StateMachine::update ()
{
	//If the state is set for the program to exit, break out of the game loop.
	if ( m_eStateID == eGameState::GAMESTATE_EXIT || m_eStateID == GAMESTATE_NULL )
	{
		return false;
	}

	//Get the time between frames.
	Uint32 uiCurrentTime = SDL_GetTicks ();
	//Increment the time elapsed since the last update call.
	m_uiElapsedTime		+= uiCurrentTime - m_uiLastTime;

	//While the update loop is behind, keep updating until it's caught up.
	while ( m_uiElapsedTime >= ciMS_FRAME_TIME )
	{
		//Update the current state.
		m_pCurrentState->handleEvents ();
		m_pCurrentState->update		  ();
		m_pInputManager->resetActions ();
		//Check for a state change following the updates.
		changeState					  ();

		//Decrement the elapsed time for every update call until we're caught up.
		m_uiElapsedTime = 0;
	}
	
	//Render the current state.
	SDL_RenderClear   ( m_pRenderer );
	m_pCurrentState->render ();
	SDL_RenderPresent ( m_pRenderer );

	//Return that the game loop should continue.
	return true;
}

void StateMachine::changeState ()
{
	//If the ID for the state change is invalid or null then we don't need to process any of this.
	if ( m_eNewStateID == GAMESTATE_NULL || m_eNewStateID >= GAMESTATE_TOTAL )
	{
		return;
	}
	if ( m_eNewStateID == GAMESTATE_NEXT )
	{
		m_eNewStateID = static_cast< eGameState >( m_eStateID + 1 );
	}

	if ( m_eNewStateID == GAMESTATE_PREVIOUS )
	{
		m_eNewStateID = static_cast< eGameState >( m_eStateID - 1 );
	}

	//If the program has been set to exit, we don't need to delete anything.
	if ( m_eNewStateID != GAMESTATE_EXIT )
	{
		cleanupState ();
	}

	//Change the current state.
	switch ( m_eNewStateID )
	{
		case GAMESTATE_SPLASHSCREEN_0 :
			m_pCurrentState = new GS_SplashScreen;
			break;
		case GAMESTATE_SPLASHSCREEN_1 :
			m_pCurrentState = new GS_SplashScreen1;
			break;
		case GAMESTATE_VIDEOINTRO :
			m_pCurrentState = new GS_VideoIntro;
			break;
		case GAMESTATE_STARTGAME:
			m_pCurrentState = new GS_StartGame;
			break;
		case GAMESTATE_MAINMENU:
			m_pCurrentState = new GS_MainMenu;
			break;
		case GAMESTATE_CHARACTERSELECT_1P:
			m_pCurrentState = new GS_CharacterSelect ( 1 );
			break;
		case GAMESTATE_CHARACTERSELECT_2P:
			m_pCurrentState = new GS_CharacterSelect ( 2 );
			break;
		default :
			printf ( "Couldn't change state. State ID does not exist." );
			break;
	}

	//Set the new state up with the necessary objects
	m_pCurrentState->setInputManager ( m_pInputManager );
	m_pCurrentState->setStateMachine ( this );
	m_pCurrentState->setFileLoader   ( m_pFileLoader   );
	m_pCurrentState->setRenderer     ( m_pRenderer     );
	m_pCurrentState->enter           ();

	//Update the state ID's to reflect the change.
	m_eStateID    = m_eNewStateID;
	m_eNewStateID = GAMESTATE_NULL;
}

void StateMachine::cleanupState ()
{
	//Destruct the current state and reset it to null.
	if ( m_pCurrentState != nullptr )
	{
		delete m_pCurrentState;
		m_pCurrentState = nullptr;
	}
}
