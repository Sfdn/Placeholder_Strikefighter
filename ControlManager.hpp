/**************************************************************
* | ControlManager Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Singleton to hold the current gamepad instances and player
* joystick ID's and act on any changes.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <SDL.h>
#include "Players.hpp"
#include "Subject.hpp"
#include "ControllerEventPacket.hpp"
#include <string>

class ControlManager : public Subject
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 ControlManager ();
	~ControlManager ();

///////////////////////////////
// | Property Accessors |
/////////////////////////////// 

	const bool isControllerActive ( const ePlayers ePlayer ) const;
	const int  getControllerID    ( const ePlayers ePlayer ) const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	static ControlManager* instance ();

	void addController      ( const int iID );
	void removeController   ( const int iID );
	void subscribeForEvents ( Observer* pObserver );
	void unsubscribe        ( Observer* pObserver );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	static ControlManager* m_psInstance;

	int*                   m_controllerID;
	int*                   m_instanceID;
	SDL_GameController**   m_pController;

};

#endif // !_H
