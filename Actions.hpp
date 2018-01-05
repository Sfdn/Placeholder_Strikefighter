/**************************************************************
* | Actions |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The enum for defining all the game's actions.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef ACTIONS_H
#define ACTIONS_H

enum eActions
{
	ACTION_INVALID			  = -1 ,
	ACTION_INTERACT				   ,
	ACTION_RETURN				   ,
	ACTION_MOVECURSOR			   ,
	ACTION_MOVESELECTIONUP		   ,
	ACTION_MOVESELECTIONDOWN	   ,
	ACTION_MOVESELECTIONLEFT	   ,
	ACTION_MOVESELECTIONRIGHT      ,
	ACTION_TOTAL
};

#endif // !GAMESTATES_H
