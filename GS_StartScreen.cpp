#include "GS_StartScreen.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

GS_StartGame::GS_StartGame ()
	: m_e           ()
	, m_pBackground ( nullptr )
{
}

GS_StartGame::~GS_StartGame ()
{
	exit ();
}

void GS_StartGame::enter ()
{
	m_pInputManager->createInputMap ( "LandingScreen" );
	setUpObjects ();
}

void GS_StartGame::handleEvents ()
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

void GS_StartGame::update ()
{
	m_pBackground->update ();

	//Change the state once the player has pressed the start button
	if ( m_pBackground->getChangedState () != GAMESTATE_NULL )
	{
		m_pStateMachine->setNewState ( m_pBackground->getChangedState () );
	}
}

void GS_StartGame::render ()
{
	m_pBackground->render ();
}

void GS_StartGame::exit ()
{
	//Destroy all the sprites and unsubscribe objects from events
	if ( m_pBackground != nullptr )
	{
		m_pBackground->unsubscribe ( m_pInputManager );
		delete m_pBackground;
	}

	m_pInputManager->removeInputMap ();
}

void GS_StartGame::setUpObjects ()
{
	//Initialise all the ingame objects with sprites and renderers, and subscribe them for events
	Sprite* pSprite = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csSTART_GAME_SCREEN + csIMAGE_EXTENSION );
	m_pBackground   = new SplashScreenBackground;
	pSprite->setRenderer             ( m_pRenderer     );
	m_pBackground->setSprite         ( pSprite         );
	m_pBackground->subscribeActions  ( m_pInputManager );
}

