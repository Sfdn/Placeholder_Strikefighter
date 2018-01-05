/**************************************************************
* | ControllerEventPacket Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This struct contains a small amount of data to be passed
* through with a controller added event for the observers
* to update their assigned player ID's.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef CONTROLLEREVENTPACKET_H
#define CONTROLLEREVENTPACKET_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameObject.hpp"
#include "Players.hpp"

struct ControllerEventPacket : public GameObject
{
	int      iID = -1;
	ePlayers ePlayer = PLAYER_INVALID;
};

#endif // !CONTROLLEREVENTPACKET_H
