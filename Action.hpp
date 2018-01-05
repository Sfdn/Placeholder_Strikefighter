/**************************************************************
* | Action Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The base class that's used to store normalised input values
* from various controls as an in-game action.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef ACTION_H
#define ACTION_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <SDL.h>
#include "Constants.hpp"
#include "Axis.hpp"
#include "Actions.hpp"
#include "Subject.hpp"
#include "Players.hpp"

class Action : public Subject , public GameObject
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	explicit Action ( const eActions eAction );

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	const eActions getAction			() const;
	const eAxis    getAxis				() const;
	const int      getValueI		    () const;
	const float    getValueF		    () const;
	const int      getConsecutiveFrames () const;
	const int      getJoystickID        () const;
	const int      getPlayer            () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void assign ( const int   iVal      = 0         , const SDL_JoystickID iJoystickID = -1             );
	void assign ( const int   iVal      = 0         , const ePlayers       ePlayer     = PLAYER_INVALID );
	void assign ( const eAxis eAxisType = AXIS_NULL , const float          fVal        = 0.0f           , const SDL_JoystickID iJoystickID = -1 )           ;
	void assign ( const eAxis eAxisType = AXIS_NULL , const float          fVal        = 0.0f           , const ePlayers       ePlayer     = PLAYER_INVALID );
	void reset  ();

private:

///////////////////////////////
// | Variables |
/////////////////////////////// 
	
	eActions       m_eActionType;
	eAxis	       m_eAxisType;
	int		       m_iValue;
	float		   m_fValue;
	int		       m_iConsecutiveFrames;
	SDL_JoystickID m_iJoystickID;
	ePlayers       m_ePlayer;
	bool           m_bProcessed;
};

#endif // !ACTION_H
