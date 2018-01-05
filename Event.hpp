/**************************************************************
* | Event Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Stores enums for use within observers to initiate events.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef EVENT_H
#define EVENT_H

enum eEvent
{
	EVENT_INVALID = -1        ,
	EVENT_FADEIN              ,
	EVENT_FADEOUT             ,
	EVENT_WAIT                ,
	EVENT_PLAYSOUND           ,
	EVENT_ASYNC_PLAYSOUND     ,
	EVENT_ASYNC_CAMERASHAKE   ,
	EVENT_CAMERASHAKE         ,
	EVENT_INPUTACTION         ,
	EVENT_CONTROLLER_ADDED    ,
	EVENT_CONTROLLER_REMOVED  ,
	EVENT_TOTAL
};

#endif // !EVENT_H
