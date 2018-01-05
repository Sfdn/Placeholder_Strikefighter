#include "GS_CharacterSelect.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

GS_CharacterSelect::GS_CharacterSelect ( const int iNumPlayers )
	: m_e                     ()
	, m_pBackground           ( nullptr                         )
	, m_buttonManager_1       ()
	, m_buttonManager_2       ()
	, m_stopwatch             ( ciCHARACTER_SELECTION_WAIT_TIME )
	, m_pCharacterPortraits_1 ( nullptr                         )
	, m_pCharacterPortraits_2 ( nullptr                         )
	, m_iNumPlayers           ( iNumPlayers                     )
{
}

GS_CharacterSelect::~GS_CharacterSelect ()
{
	exit ();
}

void GS_CharacterSelect::enter ()
{
	m_pInputManager->createInputMap ( "MainMenu" );
	setUpObjects ();
}

void GS_CharacterSelect::handleEvents ()
{
	//Poll input and pass it off to the relevant handlers
	while ( SDL_PollEvent ( &m_e ) )
	{
		switch ( m_e.type )
		{
			case SDL_QUIT:
				m_pStateMachine->setNewState ( GAMESTATE_EXIT );
				break;
			case SDL_KEYDOWN:
				m_pInputManager->processAction ( m_e , INPUTTYPE_KEYBOARD );
				break;
			case SDL_CONTROLLERAXISMOTION:
				m_pInputManager->processAction ( m_e , INPUTTYPE_CONTROLLERAXIS );
				break;
			case SDL_CONTROLLERBUTTONDOWN:
				m_pInputManager->processAction ( m_e , INPUTTYPE_CONTROLLERBUTTON );
				break;
			case SDL_CONTROLLERDEVICEADDED:
				ControlManager::instance ()->addController ( m_e.cdevice.which );
				break;
			case SDL_CONTROLLERDEVICEREMOVED:
				ControlManager::instance ()->removeController ( m_e.cdevice.which );
				break;
			default:
				break;
		}
	}
}

void GS_CharacterSelect::update ()
{
	if ( m_pBackground )
	{
		m_pBackground->update ();
	}

	m_buttonManager_1.update ();
	m_buttonManager_2.update ();

	//Tell the statemachine to change state if the managers are set to.
	if ( m_buttonManager_1.getChangedState () != GAMESTATE_NULL )
	{
		m_pStateMachine->setNewState ( m_buttonManager_1.getChangedState () );
	}
	if ( m_buttonManager_2.getChangedState () != GAMESTATE_NULL )
	{
		m_pStateMachine->setNewState ( m_buttonManager_2.getChangedState () );
	}

	//Set the new state if both characters have been selected
	if ( m_buttonManager_1.getSelected () )
	{
		if ( m_iNumPlayers > 1 )
		{
			if ( m_buttonManager_2.getSelected () )
			{
				m_pStateMachine->setNewState ( GAMESTATE_MAINMENU );
			}
		}
		else
		{
			m_pStateMachine->setNewState ( GAMESTATE_MAINMENU );
		}
	}

	//Return to the menu once the countdown timer has run out
	if ( m_stopwatch.update () )
	{
		m_pStateMachine->setNewState ( GAMESTATE_MAINMENU );
	}
}

void GS_CharacterSelect::render ()
{
	//Render all the objects
	if ( m_pBackground )
	{
		m_pBackground->render ();
	}

	m_buttonManager_1.render ();
	m_buttonManager_2.render ();

	m_pCharacterPortraits_1 [ m_buttonManager_1.getSelection () ]->render ();
	if ( m_iNumPlayers > 1 )
	{
		m_pCharacterPortraits_2 [ m_buttonManager_2.getSelection () ]->render ();
	}
}

void GS_CharacterSelect::exit ()
{
	//Destroy all the sprites and unsubscribe all the objects from events 
	if ( m_pBackground != nullptr )
	{
		SpriteFactory::destroySprite ( m_pBackground );
	}

	for ( int i = 0; i < ciNUM_CHARACTERS; i++ )
	{
		if ( m_pCharacterPortraits_1 [ i ] != nullptr )
		{
			SpriteFactory::destroySprite ( m_pCharacterPortraits_1 [ i ] );
		}

		if ( m_pCharacterPortraits_2 [ i ] != nullptr )
		{
			SpriteFactory::destroySprite ( m_pCharacterPortraits_2 [ i ] );
		}
	}

	m_buttonManager_1.unsubscribe ( m_pInputManager );
	if ( m_iNumPlayers > 1 )
	{
		m_buttonManager_2.unsubscribe ( m_pInputManager );
	}

	m_pInputManager->removeInputMap ();
}

void GS_CharacterSelect::setUpObjects ()
{
	//Initialise all the ingame objects with sprites and renderers, and subscribe them for events
	m_pBackground = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csCHARACTER_SELECT_SCREEN + csIMAGE_EXTENSION );
	m_pBackground->setRenderer         ( m_pRenderer     );
	m_buttonManager_1.init             ( m_pFileLoader   , m_pRenderer , PLAYER_1 );
	m_buttonManager_1.subscribeActions ( m_pInputManager );
	m_buttonManager_1.subscribeForInput ( PLAYER_1 );

	if ( m_iNumPlayers > 1 )
	{
		m_buttonManager_2.init              ( m_pFileLoader   , m_pRenderer , PLAYER_2 );
		m_buttonManager_2.subscribeActions  ( m_pInputManager );
		m_buttonManager_2.subscribeForInput ( PLAYER_2        );
	}

	m_pCharacterPortraits_1 = new Sprite* [ ciNUM_CHARACTERS ];
	m_pCharacterPortraits_2 = new Sprite* [ ciNUM_CHARACTERS ];
	for ( int i = 0; i < ciNUM_CHARACTERS; i++ )
	{
		m_pCharacterPortraits_1 [ i ] = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csCHARACTER + std::to_string ( i ) + csIMAGE_EXTENSION );
		m_pCharacterPortraits_1 [ i ]->setRenderer ( m_pRenderer );
		m_pCharacterPortraits_1 [ i ]->setPosition ( cvCHARACTER_PORTRAIT_P1 );

		m_pCharacterPortraits_2 [ i ] = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csCHARACTER + std::to_string ( i ) + csIMAGE_EXTENSION );
		m_pCharacterPortraits_2 [ i ]->setRenderer ( m_pRenderer );
		m_pCharacterPortraits_2 [ i ]->setPosition ( cvCHARACTER_PORTRAIT_P2 );
	}

	//Start the stopwatch based on the current time
	m_stopwatch.start ( SDL_GetTicks () );
}

