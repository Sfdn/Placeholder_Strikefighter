#include "GS_SplashScreen1.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

GS_SplashScreen1::GS_SplashScreen1 ()
	: m_e           ()
	, m_pBackground ( nullptr )
	, m_stopwatch   ( ciSPLASH_0_WAIT_TIME )
{
}

GS_SplashScreen1::~GS_SplashScreen1 ()
{
	exit ();
}

void GS_SplashScreen1::enter ()
{
	m_pInputManager->createInputMap ( "SplashScreen" );
	setUpObjects ();
}

void GS_SplashScreen1::handleEvents ()
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

void GS_SplashScreen1::update ()
{
	m_pBackground->update ();

	//Change the state if the player is skipping the screen
	if ( m_pBackground->getChangedState () != GAMESTATE_NULL )
	{
		m_pStateMachine->setNewState ( m_pBackground->getChangedState () );
	}

	//Change the state once the timer has run out
	if ( m_stopwatch.update () )
	{
		m_pStateMachine->setNewState ( GAMESTATE_NEXT );
	}
}

void GS_SplashScreen1::render ()
{
	m_pBackground->render ();
}

void GS_SplashScreen1::exit ()
{
	//Destroy all the sprites and unsubscribe objects from events
	if ( m_pBackground != nullptr )
	{
		m_pBackground->unsubscribe ( m_pInputManager );
		delete m_pBackground;
	}

	m_pInputManager->removeInputMap ();
}

void GS_SplashScreen1::setUpObjects ()
{
	//Initialise all the ingame objects with sprites and renderers, and subscribe them for events
	Sprite* pSprite = SpriteFactory::createSprite ( m_pFileLoader , csTEXTURE_PATH + csSPLASH_SCREEN_1 + csIMAGE_EXTENSION );
	m_pBackground   = new SplashScreenBackground;
	pSprite->setRenderer             ( m_pRenderer     );
	m_pBackground->setSprite         ( pSprite         );
	m_pBackground->subscribeActions  ( m_pInputManager );
	m_pBackground->subscribeForInput ( PLAYER_1        );

	m_stopwatch.start ( SDL_GetTicks () );
}
