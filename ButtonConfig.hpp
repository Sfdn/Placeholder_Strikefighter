/**************************************************************
* | ButtonConfig Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Struct to store the buttons assigned to a particular input
* method.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef BUTTONCONFIG_H
#define BUTTONCONFIG_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "InputTypes.hpp"

struct ButtonConfig
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 ButtonConfig ();
	~ButtonConfig ();

///////////////////////////////
// | Variables |
/////////////////////////////// 

	eInputTypes eInputTypeID;
	int*        piButtonID;
	int         iNumButtons;

};

#endif // !BUTTONCONFIG_H
