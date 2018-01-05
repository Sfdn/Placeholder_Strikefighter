#include "Stopwatch.hpp"

Stopwatch::Stopwatch ()
	: m_iStartTime ( 0     )
	, m_iWaitTime  ( 0     )
	, m_bStarted   ( false )
{
}

Stopwatch::Stopwatch ( const int iWaitTime )
	: m_iStartTime ( 0         )
	, m_iWaitTime  ( iWaitTime )
	, m_bStarted   ( false     )
{
}

void Stopwatch::start ( const Uint32 iStartTime )
{
	//Flag the timer to begin updating
	m_iStartTime = iStartTime;
	m_bStarted   = true;
}

void Stopwatch::start ( const Uint32 iStartTime , const int iWaitTime )
{
	//Flag the timer to begin updating
	m_iStartTime = iStartTime;
	m_iWaitTime  = iWaitTime;
	m_bStarted   = true;
}

bool Stopwatch::update ()
{
	if ( !m_bStarted )
	{
		return false;
	}

	//Return if the difference between the current time and when the timer was started is greater than the set wait time
	Uint32 iCurrentTime = SDL_GetTicks ();

	if ( iCurrentTime - m_iStartTime > m_iWaitTime )
	{
		return true;
	}

	return false;
}
