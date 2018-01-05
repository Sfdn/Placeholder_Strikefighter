/**************************************************************
* | GameStates |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The enum for all of the game's states.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GAMESTATES_H
#define GAMESTATES_H

enum eGameState
{
	GAMESTATE_NULL = -1          ,
	GAMESTATE_SPLASHSCREEN_0     ,
	GAMESTATE_SPLASHSCREEN_1     ,
	GAMESTATE_VIDEOINTRO         ,
	GAMESTATE_STARTGAME          ,
	GAMESTATE_MAINMENU           ,
	GAMESTATE_CHARACTERSELECT_1P ,
	GAMESTATE_CHARACTERSELECT_2P ,
	GAMESTATE_EXIT               ,
	GAMESTATE_NEXT               ,
	GAMESTATE_PREVIOUS           ,
	GAMESTATE_TOTAL			 
};

#endif // !GAMESTATES_H
