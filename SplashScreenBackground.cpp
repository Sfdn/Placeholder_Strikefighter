#include "SplashScreenBackground.hpp"

SplashScreenBackground::SplashScreenBackground ()
	: m_pSprite ( nullptr )
{
	m_vActionListener.push_back ( ACTION_INTERACT );
}

SplashScreenBackground::~SplashScreenBackground ()
{
	SpriteFactory::destroySprite ( m_pSprite );
}

void SplashScreenBackground::setSprite ( Sprite * pSprite )
{
	m_pSprite = pSprite;
}

void SplashScreenBackground::onNotify ( GameObject * pGameObject , const eEvent e )
{
	Action*                pAction = nullptr;
	ControllerEventPacket* pPacket = nullptr;
	switch ( e )
	{
		case EVENT_INPUTACTION :
			pAction = dynamic_cast< Action* >( pGameObject );
			m_vRetrievedActions.push_back ( pAction );
			break;
		case EVENT_CONTROLLER_ADDED :
			pPacket = dynamic_cast< ControllerEventPacket* >( pGameObject );
			controllerAdded ( pPacket );
			break;
		case EVENT_CONTROLLER_REMOVED :
			pPacket = dynamic_cast< ControllerEventPacket* >( pGameObject );
			controllerRemoved ( pPacket );
			break;
		default:
			break;
	}
}

void SplashScreenBackground::update ()
{
	if ( m_pSprite != nullptr )
	{
		m_pSprite->update ();
	}

	auto it = m_vRetrievedActions.begin ();

	for ( ; it != m_vRetrievedActions.end (); ++it )
	{
		if ( ( *it )->getJoystickID () != m_iControllerID && ( *it )->getPlayer () != m_ePlayer )
		{
			continue;
		}

		switch ( ( *it )->getAction () )
		{
			case ACTION_INTERACT :
				interact ();
				break;
			default:
				break;
		}
	}

	reset ();
}

void SplashScreenBackground::render ()
{
	if ( m_pSprite != nullptr )
	{
		m_pSprite->render ();

	}
}

void SplashScreenBackground::interact ()
{
	m_eGameState = GAMESTATE_NEXT;
}
