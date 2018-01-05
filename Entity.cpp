#include "Entity.hpp"

Entity::Entity ()
	: m_vActionListener   ()
	, m_vRetrievedActions ()
	, m_iControllerID     ( -1             )
	, m_ePlayer           ( PLAYER_INVALID )
	, m_eGameState        ( GAMESTATE_NULL )
{
}

const eGameState Entity::getChangedState ()
{
	return m_eGameState;
}

void Entity::subscribeActions ( InputManager * pInputManager )
{
	//Loop through the actions that have been pushed to the container
	//and tell the input manager to subscribe this entity for 
	//notifications on those actions.
	auto it = m_vActionListener.begin ();

	for ( ; it != m_vActionListener.end (); ++it )
	{
		pInputManager->subscribe ( this , ( *it ) );
	}
}

void Entity::subscribeForInput ( ePlayers ePlayer )
{
	//Tell the control manager to subscribe this entity
	//for input events on the specified player
	m_ePlayer = ePlayer;
	ControlManager::instance ()->subscribeForEvents ( this );

	if ( ControlManager::instance ()->isControllerActive ( m_ePlayer ) )
	{
		m_iControllerID = ControlManager::instance ()->getControllerID ( m_ePlayer );
	}
}

void Entity::unsubscribeActions ( InputManager * pInputManager )
{
	//Unsubscribe this entity from all of it's pushed actions
	auto it = m_vActionListener.begin ();

	for ( ; it != m_vActionListener.end (); ++it )
	{
		pInputManager->unsubscribe ( this , ( *it ) );
	}
}

void Entity::unsubscribe ( InputManager * pInputManager )
{
	//Unsubscribe both this entity's actions and player input
	unsubscribeActions ( pInputManager );
	unsubscribeInput   ();
}

void Entity::unsubscribeInput ()
{
	//Reset the player variables and unsubscribe from input
	m_ePlayer       = PLAYER_INVALID;
	m_iControllerID = -1;
	ControlManager::instance ()->unsubscribe ( this );
}

void Entity::reset ()
{
	//Clear the list of actions received this frame
	m_vRetrievedActions.clear ();
}

void Entity::controllerAdded ( ControllerEventPacket * pPacket )
{
	//Set up the newly added controller for the entity
	if ( pPacket->ePlayer == m_ePlayer )
	{
		m_iControllerID = pPacket->iID;
	}
}

void Entity::controllerRemoved ( ControllerEventPacket * pPacket )
{
	//Reset the controller id for the recently removed controller
	if ( pPacket->ePlayer == m_ePlayer )
	{
		m_iControllerID = -1;
	}
}
