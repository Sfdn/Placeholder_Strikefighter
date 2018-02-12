/**************************************************************
* | Stopwatch Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* A basic stopwatch utilty to return a flag after a set amount
* of time has passed.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef STOPWATCH_H
#define STOPWATCH_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <SDL.h>

class Stopwatch
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	Stopwatch ();
	Stopwatch ( const int iWaitTime );

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	const int getSecondsPassed () const;
	const int getSecondsLeft   () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void start  ( const Uint32 iStartTime );
	void start  ( const Uint32 iStartTime , const int iWaitTime );
	bool update ();

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	Uint32       m_iStartTime;
	int          m_iWaitTime;
	bool         m_bStarted;

};

#endif // !STOPWATCH_H
