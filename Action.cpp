#include "Action.hpp"

Action::Action ( const eActions eAction )
	: m_eActionType	       ( eAction        )
	, m_eAxisType		   ( AXIS_NULL      )
	, m_iValue			   ( 0			    )
	, m_fValue			   ( 0.0f		    )
	, m_iConsecutiveFrames ( 0			    )
	, m_iJoystickID        ( -1             )
	, m_ePlayer            ( PLAYER_INVALID )
	, m_iClicks            ( 0              )
	, m_iMouseX            ( -1             )
	, m_iMouseY            ( -1             )
	, m_iMouseXRel         ( 0              )
	, m_iMouseYRel         ( 0              )
	, m_bProcessed         ( false          )
{
}

const eActions Action::getAction () const
{
	return m_eActionType;
}

const eAxis Action::getAxis () const
{
	return m_eAxisType;
}

const int Action::getValueI () const
{
	return m_iValue;
}

const float Action::getValueF () const
{
	return m_fValue;
}

const int Action::getConsecutiveFrames () const
{
	return m_iConsecutiveFrames;
}

const int Action::getJoystickID () const
{
	return m_iJoystickID;
}

const int Action::getPlayer () const
{
	return m_ePlayer;
}

const int Action::getClicks () const
{
	return m_iClicks;
}

const int Action::getMouseX () const
{
	return m_iMouseX;
}

const int Action::getMouseY () const
{
	return m_iMouseY;
}

const int Action::getMouseXRel () const
{
	return m_iMouseXRel;
}

const int Action::getMouseYRel () const
{
	return m_iMouseYRel;
}

void Action::assign ( const int iVal , const SDL_JoystickID iJoystickID )
{
	m_iValue			 = iVal;
	m_iJoystickID	     = iJoystickID;
	m_bProcessed         = true;
	m_iConsecutiveFrames ++;
}

void Action::assign ( const int iVal , const ePlayers ePlayer )
{
	m_iValue     = iVal;
	m_ePlayer    = ePlayer;
	m_bProcessed = true;
	m_iConsecutiveFrames++;
}

void Action::assign ( const eAxis eAxisType , const float fVal , const SDL_JoystickID iJoystickID )
{
	m_eAxisType		     = eAxisType;
	m_fValue			 = fVal;
	m_iJoystickID        = iJoystickID;
	m_bProcessed         = true;
	m_iConsecutiveFrames ++;
}

void Action::assign ( const eAxis eAxisType , const float fVal , const ePlayers ePlayer )
{
	m_eAxisType		     = eAxisType;
	m_fValue			 = fVal;
	m_ePlayer            = ePlayer;
	m_bProcessed         = true;
	m_iConsecutiveFrames ++;
}

void Action::assign ( const int iVal , const Uint8 iClicks , const Sint32 iMouseX , const Sint32 iMouseY , const ePlayers ePlayer )
{
	m_iValue            = iVal;
	m_iClicks           = iClicks;
	m_iMouseX           = iMouseX;
	m_iMouseY           = iMouseY;
	m_ePlayer           = ePlayer;
	m_bProcessed        = true;
	m_iConsecutiveFrames++;
}

void Action::assign ( const int iVal , const Sint32 iMouseX , const Sint32 iMouseY , const Sint32 iMouseXRel , const Sint32 iMouseYRel , 
					  const ePlayers ePlayer )
{
	m_iValue	        = iVal;
	m_iMouseX	        = iMouseX;
	m_iMouseY           = iMouseY;
	m_iMouseXRel        = iMouseXRel;
	m_iMouseYRel        = iMouseYRel;
	m_ePlayer           = ePlayer;
	m_bProcessed        = true;
	m_iConsecutiveFrames++;
}

void Action::reset ()
{
	m_eAxisType   = AXIS_NULL;
	m_iValue      = 0;
	m_fValue      = 0.0f;
	m_iJoystickID = -1;
	m_ePlayer     = PLAYER_INVALID;
	m_iClicks     = 0;
	m_iMouseX     = -1;
	m_iMouseY     = -1;
	m_iMouseXRel  = 0;
	m_iMouseYRel  = 0;

	if ( !m_bProcessed )
	{
		m_iConsecutiveFrames = 0;
	}
}
