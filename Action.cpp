#include "Action.hpp"

Action::Action ( const eActions eAction )
	: m_eActionType	       ( eAction        )
	, m_eAxisType		   ( AXIS_NULL      )
	, m_iValue			   ( 0			    )
	, m_fValue			   ( 0.0f		    )
	, m_iConsecutiveFrames ( 0			    )
	, m_iJoystickID        ( -1             )
	, m_ePlayer            ( PLAYER_INVALID )
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

void Action::reset ()
{
	m_eAxisType   = AXIS_NULL;
	m_iValue      = 0;
	m_fValue      = 0.0f;
	m_iJoystickID = -1;
	m_ePlayer     = PLAYER_INVALID;

	if ( !m_bProcessed )
	{
		m_iConsecutiveFrames = 0;
	}
}
