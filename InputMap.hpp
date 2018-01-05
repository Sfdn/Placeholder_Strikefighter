/**************************************************************
* | InputMap Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Stores all the parsed data from a .inputmap file to assign
* actions to the correct bindings.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef INPUTMAP_H
#define INPUTMAP_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "InputMapAction.hpp"

struct InputMap
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	InputMap  ();
	~InputMap ();

///////////////////////////////
// | Variables |
/////////////////////////////// 

	InputMapAction* pMappedAction;
	int             iNumMappedActions;

};

#endif // !INPUTMAP_H
