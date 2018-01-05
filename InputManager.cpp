#include "InputManager.hpp"

InputManager::InputManager ()
	: m_mapKeyboardActions         ()
	, m_mapMouseActions            ()
	, m_mapControllerButtonActions ()
	, m_mapControllerAxisActions   ()
	, m_vPossibleActions           ()
	, m_vActiveActions             ()
{
	createActions ();
}

InputManager::~InputManager ()
{
	//Delete all pointers and clear the containers that were using them.
	deleteActions ();
	clearVectors  ();
	clearMaps     ();
}

const std::vector<Action*>& InputManager::getActions () const
{
	return m_vPossibleActions;
}

void InputManager::createInputMap ( const std::string & sMapName )
{
	//Create an input map from the passed in filename
	InputMap* pInputMap = InputMapper::createInputMap ( sMapName );

	//Loop through all the actions in the map and set them up with the correct input ID's
	for ( int i = 0; i < pInputMap->iNumMappedActions; i++ )
	{
		mapActionToInput ( pInputMap->pMappedAction [ i ] );
	}
}

void InputManager::removeInputMap ()
{
	clearMaps ();
}

void InputManager::processAction ( const SDL_Event& e , const int iInputType )
{
	//Retrieve an action object from a passed in input event.
	Action* action = nullptr;
	switch ( iInputType )
	{
		case INPUTTYPE_KEYBOARD :
			action = getKeyboardAction ( e );
			break;
		case INPUTTYPE_CONTROLLERBUTTON :
			action = getControllerButtonAction ( e );
			break;
		case INPUTTYPE_CONTROLLERAXIS :
			action = getControllerAxisAction ( e );
			break;
		default:
			break;
	}

	if ( action == nullptr )
	{
		return;
	}

	//Notify the subscribed entities of an input action
	m_vActiveActions.push_back ( action );
	action->notify ( action , EVENT_INPUTACTION );
}

void InputManager::resetActions ()
{
	//Reset all the currently active actions
	auto it = m_vActiveActions.begin ();
	for ( ; it != m_vActiveActions.end (); ++it )
	{
		( *it )->reset ();
	}
	m_vActiveActions.clear ();
}

void InputManager::subscribe ( Observer * pObserver , eActions eAction )
{
	//Find the action that matches and subscribe the passed in entity
	auto it = m_vPossibleActions.begin ();

	for ( ; it != m_vPossibleActions.end (); ++it )
	{
		if ( ( *it )->getAction () == eAction )
		{
			( *it )->addObserver ( pObserver );
			return;
		}
	}
}

void InputManager::unsubscribe ( Observer * pObserver , eActions eAction )
{
	//Find the action that matches and unsubscribe the passed in entity
	auto it = m_vPossibleActions.begin ();

	for ( ; it != m_vPossibleActions.end (); ++it )
	{
		if ( ( *it )->getAction () == eAction )
		{
			( *it )->removeObserver ( pObserver );
			return;
		}
	}
}

void InputManager::createActions ()
{
	//Loop through all the action enums and create assigned action objects and add them to a container.
	for ( int i = 0; i < ACTION_TOTAL; i++ )
	{
		Action* action = new Action ( static_cast< eActions >( i ) );
		m_vPossibleActions.push_back ( action );
	}
}

void InputManager::deleteActions ()
{
	//Delete all the created actions.
	for ( std::vector<Action*>::iterator it = m_vPossibleActions.begin (); it != m_vPossibleActions.end (); ++it )
	{
		if ( ( *it ) != nullptr )
		{
			delete ( *it );
		}
	}
}

void InputManager::clearVectors ()
{
	m_vPossibleActions.clear ();
	m_vActiveActions  .clear ();
}

void InputManager::clearMaps ()
{
	m_mapKeyboardActions        .clear ();
	m_mapMouseActions           .clear ();
	m_mapControllerButtonActions.clear ();
	m_mapControllerAxisActions  .clear ();
}

void InputManager::mapActionToInput ( const InputMapAction& mapAction )
{
	//Get the correct action object
	Action* pAction = retrieveActionFromID ( mapAction.eActionID );

	//Break out if no action was returned.
	if ( pAction == nullptr )
	{
		return;
	}

	//Loop through all the button config objects and assign them to the correct container.
	for ( int i = 0; i < mapAction.iNumButtonConfigs; i++ )
	{
		mapButtonConfig ( mapAction.pButtonConfig [ i ] , pAction );
	}
}

void InputManager::mapButtonConfig ( const ButtonConfig & buttonConfig , Action * pAction )
{
	//Get the correct container for the input type.
	std::map<const int , Action*>* pMap = retrieveMapFromID ( buttonConfig.eInputTypeID );

	//Break out if no correct map was found.
	if ( pMap == nullptr )
	{
		return;
	}

	//Loop through all the buttons and assign the action to the map using the button index as the key.
	for ( int i = 0; i < buttonConfig.iNumButtons; i++ )
	{
		( *pMap ) [ buttonConfig.piButtonID [ i ] ] = pAction;
	}
}

Action * InputManager::retrieveActionFromID ( const eActions eID )
{
	std::vector<Action*>::iterator it = m_vPossibleActions.begin ();

	//Loop through the vector of available actions and return the one that matches the passed in ID
	while ( it != m_vPossibleActions.end () )
	{
		if ( ( *it )->getAction () == eID )
		{
			return ( *it );
		}

		++it;
	}

	//If none match, return nullptr.
	return nullptr;
}

std::map<const int , Action*>* InputManager::retrieveMapFromID ( const eInputTypes eID )
{
	//Return the correct container based on the passed in input type.
	switch ( eID )
	{
		case INPUTTYPE_NULL             :
			return nullptr;
		case INPUTTYPE_KEYBOARD         :
			return &m_mapKeyboardActions;
		case INPUTTYPE_MOUSE            :
			return &m_mapMouseActions;
		case INPUTTYPE_CONTROLLERBUTTON :
			return &m_mapControllerButtonActions;
		case INPUTTYPE_CONTROLLERAXIS   :
			return &m_mapControllerAxisActions;
		default:
			return nullptr;
	}
}

Action * InputManager::getKeyboardAction ( const SDL_Event & e ) const
{
	const int iIndex       = e.key.keysym.scancode;
	Action*   action	   = nullptr;

	//Find the correct action mapped to the pressed input
	if ( m_mapKeyboardActions.count ( iIndex ) )
	{
		action = m_mapKeyboardActions.at ( iIndex );
	}

	//Assign it the relevant passed in information
	if ( action != nullptr )
	{
		action->assign ( e.cbutton.state , PLAYER_1 );
	}

	return action;
}

Action * InputManager::getControllerButtonAction ( const SDL_Event& e ) const
{
	const int iIndex       = e.cbutton.button;
	Action*   action	   = nullptr;

	//Find the correct action mapped to the pressed input
	if ( m_mapControllerButtonActions.count ( iIndex ) )
	{
		action = m_mapControllerButtonActions.at ( iIndex );
	}

	//Assign it the relevant passed in information
	if ( action != nullptr )
	{
		action->assign ( e.cbutton.state , e.cbutton.which );
	}

	return action;
}

Action * InputManager::getControllerAxisAction ( const SDL_Event & e ) const
{
	const int iIndex = e.caxis.axis;
	Action*   action = nullptr;

	//Find the correct action mapped to the pressed input
	if ( m_mapControllerAxisActions.count ( iIndex ) )
	{
		action = m_mapControllerAxisActions.at ( iIndex );
	}

	//Assign it the relevant passed in information
	if ( action != nullptr )
	{
		//Normalise the axis value to a range between -1 and 1
		const float f = normaliseAxisValue ( e.caxis.value );
		action->assign ( static_cast< eAxis >( e.caxis.axis ) , f , e.caxis.which );
	}

	return action;
}

const float InputManager::normaliseAxisValue ( const int iVal ) const
{
	float f = 0.0f;

	if ( iVal > 0 )
	{
		f = static_cast< float >( iVal ) / static_cast< float >( ciAXIS_MAX );
	}
	else if ( iVal < 0 )
	{
		int uiVal = -iVal;
		int uiMin = -ciAXIS_MIN;
		f = -( static_cast< float >( uiVal ) / static_cast< float >( uiMin ) );
	}

	return f;
}
