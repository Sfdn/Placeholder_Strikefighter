#include "CharacterSelectionButtonManager.hpp"

CharacterSelectionButtonManager::CharacterSelectionButtonManager ()
	: m_mainMenuButton   ( nullptr )
	, m_vButtonPositions ( nullptr )
	, m_iCurrentButton ( 0 )
{

}

CharacterSelectionButtonManager::~CharacterSelectionButtonManager ()
{
	if ( m_mainMenuButton != nullptr )
	{
		delete [] m_mainMenuButton;
	}

	if ( m_vButtonPositions != nullptr )
	{
		delete [] m_vButtonPositions;
	}
}

const int CharacterSelectionButtonManager::getSelection () const
{
	return m_iSelection;
}

const bool CharacterSelectionButtonManager::getSelected () const
{
	return m_bSelected;
}

void CharacterSelectionButtonManager::init ( FileLoader * pFileLoader , SDL_Renderer * pRenderer , ePlayers ePlayer )
{
	m_mainMenuButton = new MainMenuButton [ ciNUM_CHARACTERS ];
	//Currently hardcoded positions for the selector based on the position of placeholder player buttons
	m_vButtonPositions = new Vector3<float> [ ciNUM_CHARACTERS ]
	{ { 120.0f  , 548.0f , 0.0f }
	, { 328.0f  , 548.0f , 0.0f }
	, { 536.0f  , 548.0f , 0.0f }
	, { 744.0f  , 548.0f , 0.0f }
	, { 953.0f  , 548.0f , 0.0f }
	, { 1161.0f , 548.0f , 0.0f }
	, { 16.0f   , 643.0f , 0.0f }
	, { 224.0f  , 643.0f , 0.0f }
	, { 432.0f  , 643.0f , 0.0f }
	, { 640.0f  , 643.0f , 0.0f }
	, { 849.0f  , 643.0f , 0.0f }
	, { 1057.0f , 643.0f , 0.0f }
	};

	//Set up the string path correctly based on the number of players
	std::string sSelector;
	switch ( ePlayer )
	{
		case PLAYER_1:
			sSelector = csCHARACTER_SELECTOR_0;
			break;
		case PLAYER_2:
			sSelector = csCHARACTER_SELECTOR_1;
			m_iCurrentButton = ciNUM_CHARACTERS - 1;
			break;
		default:
			break;
	}
	//Set up the character selectors with sprites, renderers and the correct positions
	for ( int i = 0; i < ciNUM_CHARACTERS; i++ )
	{
		m_mainMenuButton [ i ].setSprite ( SpriteFactory::createSprite ( pFileLoader , csTEXTURE_PATH + sSelector + csIMAGE_EXTENSION ) );
		m_mainMenuButton [ i ].getSprite ()->setRenderer ( pRenderer );
		m_mainMenuButton [ i ].getSprite ()->setPosition ( m_vButtonPositions [ i ] );
	}

	m_mainMenuButton [ m_iCurrentButton ].setActive ( true );

	//Subscribe this object to listen to the correct actions
	m_vActionListener.push_back ( ACTION_INTERACT );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONUP );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONDOWN );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONLEFT );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONRIGHT );
}

void CharacterSelectionButtonManager::update ()
{
	if ( m_mainMenuButton == nullptr )
	{
		return;
	}

	auto it = m_vRetrievedActions.begin ();

	//Check if retrieved input matches the player the entity is listening for
	for ( ; it != m_vRetrievedActions.end (); ++it )
	{
		if ( ( *it )->getJoystickID () != m_iControllerID )
		{
			if ( ( *it )->getPlayer () != m_ePlayer )
			{
				continue;
			}
		}

		//React to various input
		switch ( ( *it )->getAction () )
		{
			case ACTION_INTERACT:
				interact ();
				break;
			case ACTION_MOVESELECTIONDOWN:
				moveSelectionY ( 1 );
				break;
			case ACTION_MOVESELECTIONUP:
				moveSelectionY ( -1 );
				break;
			case ACTION_MOVESELECTIONLEFT:
				moveSelectionX ( -1 );
				break;
			case ACTION_MOVESELECTIONRIGHT:
				moveSelectionX ( 1 );
				break;
			default:
				break;
		}
	}

	reset ();
}

void CharacterSelectionButtonManager::render ()
{
	if ( m_mainMenuButton == nullptr )
	{
		return;
	}

	m_mainMenuButton [ m_iCurrentButton ].render ();
}

void CharacterSelectionButtonManager::onNotify ( GameObject * pGameObject , const eEvent e )
{
	//Delegate event based on type
	Action*                pAction = nullptr;
	ControllerEventPacket* pPacket = nullptr;
	switch ( e )
	{
		case EVENT_INPUTACTION:
			pAction = dynamic_cast< Action* >( pGameObject );
			m_vRetrievedActions.push_back ( pAction );
			break;
		case EVENT_CONTROLLER_ADDED:
			pPacket = dynamic_cast< ControllerEventPacket* >( pGameObject );
			controllerAdded ( pPacket );
			break;
		case EVENT_CONTROLLER_REMOVED:
			pPacket = dynamic_cast< ControllerEventPacket* >( pGameObject );
			controllerRemoved ( pPacket );
			break;
		default:
			break;
	}
}

void CharacterSelectionButtonManager::interact ()
{
	if ( !m_bSelected )
	{
		m_bSelected  = true;
	}
}

void CharacterSelectionButtonManager::moveSelectionX ( const int iDirection )
{
	if ( m_bSelected )
	{
		return;
	}
	m_mainMenuButton [ m_iCurrentButton ].setActive ( false );
	m_iCurrentButton += iDirection;

	if ( m_iCurrentButton >= ciNUM_CHARACTERS )
	{
		m_iCurrentButton = 0;
	}
	else if ( m_iCurrentButton < 0 )
	{
		m_iCurrentButton = ciNUM_CHARACTERS - 1;
	}

	m_iSelection = m_iCurrentButton;
	m_mainMenuButton [ m_iCurrentButton ].setActive ( true );
}

void CharacterSelectionButtonManager::moveSelectionY ( const int iDirection )
{
	if ( m_bSelected )
	{
		return;
	}
	m_mainMenuButton [ m_iCurrentButton ].setActive ( false );
	m_iCurrentButton += static_cast< int >( ciNUM_CHARACTERS / 2 );

	if ( m_iCurrentButton >= ciNUM_CHARACTERS )
	{
		m_iCurrentButton -= ciNUM_CHARACTERS;
	}

	m_iSelection = m_iCurrentButton;
	m_mainMenuButton [ m_iCurrentButton ].setActive ( true );
}

