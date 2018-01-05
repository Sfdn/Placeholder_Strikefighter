/**************************************************************
* | Observer Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The observer class is used for implementing the Observer 
* pattern. Observers are notified of changes to their subcribed
* subject systems.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef OBSERVER_H
#define OBSERVER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Event.hpp"
#include "GameObject.hpp"

class Observer
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	virtual ~Observer () {};

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void onNotify ( GameObject* pGameObject , const eEvent e ) = 0;
};

#endif // !_H
