/**************************************************************
* | Entity Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* An expansion of the game object class, with the inclusion
* of a transform and containers for action receiving.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef ENTITY_H
#define ENTITY_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <vector>
#include "GameObject.hpp"
#include "Transform.hpp"
#include "Action.hpp"
#include "InputManager.hpp"
#include "ControlManager.hpp"
#include "GameStates.hpp"

class Entity : public GameObject , public Observer
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         Entity ();
	virtual ~Entity () {};

///////////////////////////////
// | Property Accessors |
///////////////////////////////
	
	const eGameState getChangedState ();

///////////////////////////////
// | Methods |
///////////////////////////////

	void subscribeActions   ( InputManager* pInputManager );
	void subscribeForInput  ( ePlayers ePlayer            );
	void unsubscribeActions ( InputManager* pInputManager );
	void unsubscribe        ( InputManager* pInputManager );
	void unsubscribeInput   ();
	void reset              ();

protected:

///////////////////////////////
// | Variables |
///////////////////////////////

	std::vector<eActions> m_vActionListener;
	std::vector<Action*>  m_vRetrievedActions;

	int					  m_iControllerID;
	ePlayers              m_ePlayer;
	eGameState            m_eGameState;

///////////////////////////////
// | Methods |
///////////////////////////////

	void controllerAdded   ( ControllerEventPacket* pPacket );
	void controllerRemoved ( ControllerEventPacket* pPacket );

};

#endif // !ENTITY_H
