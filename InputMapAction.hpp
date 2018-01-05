/**************************************************************
* | InputMapAction Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Stores an action parsed from a .inputmap file. Contains an
* action enum and an array of button configurations per input
* type.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef INPUTMAPACTION_H
#define INPUTMAPACTION_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Actions.hpp"
#include "ButtonConfig.hpp"

struct InputMapAction
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	InputMapAction  ();
	~InputMapAction ();

///////////////////////////////
// | Variables |
/////////////////////////////// 

	eActions      eActionID;
	ButtonConfig* pButtonConfig;
	int           iNumButtonConfigs;

};

#endif // !INPUTMAPACTION_H
