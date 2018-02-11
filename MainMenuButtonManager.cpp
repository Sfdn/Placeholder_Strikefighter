#include "MainMenuButtonManager.hpp"

MainMenuButtonManager::MainMenuButtonManager ()
	: m_mainMenuButton          ( nullptr )
	, m_vButtonPositions        ( nullptr )
	, m_iCurrentButton          ( 0       )
	, m_pConfirmDialogueBox     ( nullptr )
	, m_confirmBoxButton        ( nullptr )
	, m_vConfirmButtonPositions ( nullptr )
	, m_iConfirmButton          ( 0       )
	, m_bShowConfirmBox         ( false   )
{
	m_mainMenuButton   = new MainMenuButton [ ciNumMenuButtons ];
	m_vButtonPositions = new Vector3<float> [ ciNumMenuButtons ]
	{ { 60.0f  , 195.0f , 0.0f } 
	, { 160.0f , 264.0f , 0.0f }  
	, { 256.0f , 334.0f , 0.0f } 
	, { 445.0f , 400.0f , 0.0f } 
	, { 580.0f , 465.0f , 0.0f } 
	, { 755.0f , 530.0f , 0.0f }
	};

	m_confirmBoxButton        = new MainMenuButton [ ciNumConfirmButtons ];
	m_vConfirmButtonPositions = new Vector3<float> [ ciNumConfirmButtons ]
	{ { 525.0f , 385.0f , 0.0f }
	, { 705.0f , 385.0f , 0.0f }
	};
}

MainMenuButtonManager::~MainMenuButtonManager ()
{
	if ( m_mainMenuButton != nullptr )
	{
		delete [] m_mainMenuButton;
	}

	if ( m_vButtonPositions != nullptr )
	{
		delete [] m_vButtonPositions;
	}

	if ( m_confirmBoxButton != nullptr )
	{
		delete [] m_confirmBoxButton;
	}

	if ( m_vConfirmButtonPositions != nullptr )
	{
		delete [] m_vConfirmButtonPositions;
	}
}

void MainMenuButtonManager::init ( FileLoader * pFileLoader , SDL_Renderer * pRenderer )
{
	for ( int i = 0; i < ciNumMenuButtons; i++ )
	{
		m_mainMenuButton [ i ].setSprite ( SpriteFactory::createSprite ( pFileLoader , csTEXTURE_PATH + csMAIN_MENU_SELECTOR + csIMAGE_EXTENSION ) );
		m_mainMenuButton [ i ].getSprite ()->setRenderer ( pRenderer );
		m_mainMenuButton [ i ].getSprite ()->setPosition ( m_vButtonPositions [ i ] );
	}

	for ( int j = 0; j < ciNumConfirmButtons; j++ )
	{
		m_confirmBoxButton [ j ].setSprite ( SpriteFactory::createSprite ( pFileLoader , csTEXTURE_PATH + csMAIN_MENU_SELECTOR_5 + csIMAGE_EXTENSION ) );
		m_confirmBoxButton [ j ].getSprite ()->setRenderer ( pRenderer );
		m_confirmBoxButton [ j ].getSprite ()->setPosition ( m_vConfirmButtonPositions [ j ] );
	}

	m_pConfirmDialogueBox = SpriteFactory::createSprite ( pFileLoader , csTEXTURE_PATH + csMAIN_MENU_CONFIRM_BOX + csIMAGE_EXTENSION );
	m_pConfirmDialogueBox->setRenderer ( pRenderer );
	m_pConfirmDialogueBox->setPosition ( { ciSCREEN_WIDTH/2 - static_cast< float >( m_pConfirmDialogueBox->getWidth () ) / 2 , ciSCREEN_HEIGHT/2 - static_cast< float >( m_pConfirmDialogueBox->getHeight () ) / 2 , 0.0f } );

	m_mainMenuButton   [ m_iCurrentButton ].setActive ( true );
	m_confirmBoxButton [ m_iConfirmButton ].setActive ( true );

	m_vActionListener.push_back ( ACTION_INTERACT           );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONUP    );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONDOWN  );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONLEFT  );
	m_vActionListener.push_back ( ACTION_MOVESELECTIONRIGHT );
}

void MainMenuButtonManager::update ()
{
	auto it = m_vRetrievedActions.begin ();

	for ( ; it != m_vRetrievedActions.end (); ++it )
	{
		if ( ( *it )->getJoystickID () != m_iControllerID && ( *it )->getPlayer () != m_ePlayer )
		{
			continue;
		}

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

void MainMenuButtonManager::render ()
{
	m_mainMenuButton [ m_iCurrentButton ].render ();

	if ( m_bShowConfirmBox )
	{
		m_pConfirmDialogueBox->render ();
		m_confirmBoxButton [ m_iConfirmButton ].render ();
	}
}

void MainMenuButtonManager::onNotify ( GameObject * pGameObject , const eEvent e )
{
	Action*                pAction = nullptr;
	ControllerEventPacket* pPacket = nullptr;
	switch ( e )
	{
		case EVENT_INPUTACTION:
			pAction = dynamic_cast< Action* >( pGameObject );
			m_vRetrievedActions.push_back    ( pAction );
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

void MainMenuButtonManager::interact ()
{
	if ( !m_bShowConfirmBox )
	{
		switch ( m_iCurrentButton )
		{
			case 0:
				m_eGameState = GAMESTATE_CHARACTERSELECT_1P;
				break;
			case 1:
				m_eGameState = GAMESTATE_CHARACTERSELECT_2P;
				break;
			case 5:
				m_bShowConfirmBox = true;
				break;
			default:
				break;
		}
	}	
	else
	{
		switch ( m_iConfirmButton )
		{
			case 0:
				m_eGameState = GAMESTATE_EXIT;
				break;
			case 1:
				m_bShowConfirmBox = false;
				break;
			default:
				break;
		}
	}
}

void MainMenuButtonManager::moveSelectionX ( const int iDirection )
{
	if ( !m_bShowConfirmBox )
	{
		return;
	}
	m_confirmBoxButton [ m_iConfirmButton ].setActive ( false );
	m_iConfirmButton += iDirection;

	if ( m_iConfirmButton >= ciNumConfirmButtons )
	{
		m_iConfirmButton = 0;
	}
	else if ( m_iConfirmButton < 0 )
	{
		m_iConfirmButton = ciNumConfirmButtons - 1;
	}

	m_confirmBoxButton [ m_iConfirmButton ].setActive ( true );
}

void MainMenuButtonManager::moveSelectionY ( const int iDirection )
{
	if ( m_bShowConfirmBox )
	{
		return;
	}
	m_mainMenuButton [ m_iCurrentButton ].setActive ( false );
	m_iCurrentButton += iDirection;

	if ( m_iCurrentButton >= ciNumMenuButtons )
	{
		m_iCurrentButton = 0;
	}
	else if ( m_iCurrentButton < 0 )
	{
		m_iCurrentButton = ciNumMenuButtons - 1;
	}

	m_mainMenuButton [ m_iCurrentButton ].setActive ( true );
}
