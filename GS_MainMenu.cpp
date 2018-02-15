#include "GS_MainMenu.hpp" 
#include "InputManager.hpp"
#include "StateMachine.hpp"

GS_MainMenu::GS_MainMenu ()
	: m_e             ()
	, m_pBackground   ( nullptr )
	, m_buttonManager ()
{
}

GS_MainMenu::~GS_MainMenu ()
{
	exit ();
}

void GS_MainMenu::enter ()
{
	m_pInputManager->createInputMap ( "MainMenu" );
	setUpObjects ();
}

void GS_MainMenu::handleEvents ()
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
			case SDL_MOUSEMOTION:
				m_pInputManager->processAction ( m_e , INPUTTYPE_MOUSEMOTION );
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_pInputManager->processAction ( m_e , INPUTTYPE_MOUSEBUTTON );
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

void GS_MainMenu::update ()
{
	if ( m_pBackground )
	{
		m_pBackground->update ();
	}

	//Change the state if a button has been pressed
	m_buttonManager.update ();
	if ( m_buttonManager.getChangedState () != GAMESTATE_NULL )
	{
		m_pStateMachine->setNewState ( m_buttonManager.getChangedState () );
	}
}

void GS_MainMenu::render ()
{
	if ( m_pBackground )
	{
		m_pBackground->render ();
	}

	m_buttonManager.render ();
}

void GS_MainMenu::exit ()
{
	//Destroy all the sprites and unsubscribe objects from events
	if ( m_pBackground != nullptr )
	{
		SpriteFactory::destroySprite       ( m_pBackground   );
	}
	
	m_buttonManager.unsubscribeActions ( m_pInputManager );
	m_pInputManager->removeInputMap ();
}

void GS_MainMenu::setUpObjects ()
{
	//Initialise all the ingame objects with sprites and renderers, and subscribe them for events
	m_pBackground = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csMAIN_MENU_SCREEN + csIMAGE_EXTENSION );
	m_pBackground->setRenderer        ( m_pRenderer );
	m_buttonManager.init              ( m_pFileLoader   , m_pRenderer );
	m_buttonManager.subscribeActions  ( m_pInputManager );
	m_buttonManager.subscribeForInput ( PLAYER_1        );
}
