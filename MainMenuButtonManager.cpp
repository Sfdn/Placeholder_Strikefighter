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
	m_mainMenuButton   = new MainMenuButton [ ciNUM_MENU_BUTTONS ];
	m_vButtonPositions = new Vector3<float> [ ciNUM_MENU_BUTTONS ]
	{ { 40.0f  , 215.0f , 0.0f } 
	, { 125.0f , 284.0f , 0.0f }  
	, { 220.0f , 350.0f , 0.0f } 
	, { 410.0f , 420.0f , 0.0f } 
	, { 550.0f , 485.0f , 0.0f } 
	, { 720.0f , 550.0f , 0.0f }
	};

	m_confirmBoxButton        = new MainMenuButton [ ciNUM_CONFIRM_BUTTONS ];
	m_vConfirmButtonPositions = new Vector3<float> [ ciNUM_CONFIRM_BUTTONS ]
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
	for ( int i = 0; i < ciNUM_MENU_BUTTONS; i++ )
	{
		m_mainMenuButton [ i ].setSprite ( SpriteFactory::createSprite ( pFileLoader , csTEXTURE_PATH + csMAIN_MENU_SELECTOR + csIMAGE_EXTENSION ) );
		m_mainMenuButton [ i ].getSprite ()->setRenderer ( pRenderer );
		m_mainMenuButton [ i ].getSprite ()->setPosition ( m_vButtonPositions [ i ] );
	}

	for ( int j = 0; j < ciNUM_CONFIRM_BUTTONS; j++ )
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
	m_vActionListener.push_back ( ACTION_RETURN             );
	m_vActionListener.push_back ( ACTION_MOVECURSOR         );
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
			case ACTION_RETURN:
				back ();
				break;
			case ACTION_MOVECURSOR:
				moveCursor ( *it );
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

void MainMenuButtonManager::back ()
{
	m_eGameState = GAMESTATE_STARTGAME;
}

void MainMenuButtonManager::moveCursor ( Action* action )
{
	int x = action->getMouseX ();
	int y = action->getMouseY ();

	if ( !m_bShowConfirmBox )
	{
		for ( int i = 0; i < ciNUM_MENU_BUTTONS; i++ )
		{
			if ( x < m_vButtonPositions [ i ].x ||
				 x > m_vButtonPositions [ i ].x + 300 ||
				 y < m_vButtonPositions [ i ].y ||
				 y > m_vButtonPositions [ i ].y + 80 )
			{
				continue;
			}

			m_mainMenuButton [ m_iCurrentButton ].setActive ( false );
			m_iCurrentButton = i;
			m_mainMenuButton [ m_iCurrentButton ].setActive ( true );
		}
	}
	else
	{
		for ( int i = 0; i < ciNUM_CONFIRM_BUTTONS; i++ )
		{
			if ( x < m_vConfirmButtonPositions [ i ].x ||
				 x > m_vConfirmButtonPositions [ i ].x + 150 ||
				 y < m_vConfirmButtonPositions [ i ].y ||
				 y > m_vConfirmButtonPositions [ i ].y + 100 )
			{
				continue;
			}

			m_confirmBoxButton [ m_iConfirmButton ].setActive ( false );
			m_iConfirmButton = i;
			m_confirmBoxButton [ m_iConfirmButton ].setActive ( true );
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

	if ( m_iConfirmButton >= ciNUM_CONFIRM_BUTTONS )
	{
		m_iConfirmButton = 0;
	}
	else if ( m_iConfirmButton < 0 )
	{
		m_iConfirmButton = ciNUM_CONFIRM_BUTTONS - 1;
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

	if ( m_iCurrentButton >= ciNUM_MENU_BUTTONS )
	{
		m_iCurrentButton = 0;
	}
	else if ( m_iCurrentButton < 0 )
	{
		m_iCurrentButton = ciNUM_MENU_BUTTONS - 1;
	}

	m_mainMenuButton [ m_iCurrentButton ].setActive ( true );
}
