/**************************************************************
* | Input Types |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Enum for the different input types for actions.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef INPUTTYPES_H
#define INPUTTYPES_H

enum eInputTypes
{
	INPUTTYPE_NULL = -1        ,
	INPUTTYPE_KEYBOARD         ,
	INPUTTYPE_MOUSEMOTION      ,
	INPUTTYPE_MOUSEBUTTON      ,
	INPUTTYPE_CONTROLLERBUTTON ,
	INPUTTYPE_CONTROLLERAXIS   ,
	INPUTTYPE_TOTAL
};

#endif // !INPUTTYPES_H
