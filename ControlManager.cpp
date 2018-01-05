#include "ControlManager.hpp"

ControlManager* ControlManager::m_psInstance = nullptr;

ControlManager::ControlManager ()
	: m_controllerID ( new int                 [ PLAYER_TOTAL ] )
	, m_instanceID   ( new int                 [ PLAYER_TOTAL ] )
	, m_pController  ( new SDL_GameController* [ PLAYER_TOTAL ] )
{
	for ( int i = 0; i < PLAYER_TOTAL; i++ )
	{
		m_controllerID [ i ] = -1;
		m_instanceID   [ i ] = -1;
		m_pController  [ i ] = nullptr;
	}
}

ControlManager::~ControlManager ()
{
	if ( m_controllerID != nullptr )
	{
		delete [] m_controllerID;
	}

	if ( m_pController != nullptr )
	{
		delete [] m_controllerID;
	}
}

const bool ControlManager::isControllerActive ( const ePlayers ePlayer ) const
{
	//Check if there is a controller active for the passed in player
	if ( m_controllerID [ ePlayer ] == -1 )
	{
		return false;
	}

	return true;
}

const int ControlManager::getControllerID ( const ePlayers ePlayer ) const
{
	return m_controllerID [ ePlayer ];
}

ControlManager * ControlManager::instance ()
{
	//Create a singleton instance or return the singleton
	if ( !m_psInstance )
	{
		m_psInstance = new ControlManager;
	}

	return m_psInstance;
}

void ControlManager::addController ( const int iID )
{
	//NOTE: CURRENTLY HARDCODED TO ONLY SPECIFY PLAYER 2 DUE TO 
	//THE CONTROL SCHEME MENTIONED FOR THIS COMMISSION

	//Check if there is a joystick connected at this ID
	if ( SDL_IsGameController ( iID ) )
	{
		//Open a controller and store it's pointer
		m_pController  [ PLAYER_2 ] = SDL_GameControllerOpen ( iID );

		//f the controller opened successfully
		if ( m_pController [ PLAYER_2 ] )
		{
			//Get all the relevant ID's for the controller and store them
			SDL_Joystick* pJoy          = SDL_GameControllerGetJoystick ( m_pController [ PLAYER_2 ] );
			m_instanceID   [ PLAYER_2 ] = SDL_JoystickInstanceID ( pJoy );
			m_controllerID [ PLAYER_2 ] = iID;

			//Send out a notification to all entities subscribed for notifications to input
			ControllerEventPacket packet;
			packet.iID     = iID;
			packet.ePlayer = PLAYER_2;

			notify ( &packet , EVENT_CONTROLLER_ADDED );

			std::cout << "Controller added with id " << iID << " for player " << PLAYER_2 << "." << std::endl;
		}		
		else
		{
			std::cout << "Couldn't open controller " << iID << "." << std::endl;
		}
	}
}

void ControlManager::removeController ( const int iID )
{
	//Loop through the number of player's available
	for ( int i = 0; i < PLAYER_TOTAL; i++ )
	{
		//Check for an ID match
		if ( m_instanceID [ i ] == iID )
		{
			//Close the controller if it's open
			if ( SDL_IsGameController ( m_controllerID [ i ] ) )
			{
				SDL_GameControllerClose ( m_pController [ i ] );

				//Send out a notification to subscribed entities
				ControllerEventPacket packet;
				packet.iID     = i;
				packet.ePlayer = PLAYER_2;

				notify ( &packet , EVENT_CONTROLLER_REMOVED );

				std::cout << "Controller removed with id " << m_controllerID [ i ] << " for player " << PLAYER_2 << "." << std::endl;
				m_controllerID [ i ] = -1;
				m_instanceID   [ i ] = -1;
			}
			else
			{
				std::cout << "Controller " << m_controllerID [ i ] << " not removed as it doesn't exist." << std::endl;
			}
		}
	}	
}

void ControlManager::subscribeForEvents ( Observer * pObserver )
{
	addObserver ( pObserver );
}

void ControlManager::unsubscribe ( Observer * pObserver )
{
	removeObserver ( pObserver );
}
