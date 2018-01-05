/**************************************************************
* | Subject Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The subject class is used for game objects to subscribe
* to to be notified of changes.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef SUBJECT_H
#define SUBJECT_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Constants.hpp"
#include "Observer.hpp"
#include "Event.hpp"

class Subject
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 Subject ();
	~Subject ();

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void addObserver    ( Observer* pObserver );
	void removeObserver ( Observer* pObserver );
	void notify         ( GameObject* pGameObject , const eEvent e );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	Observer* m_pObservers   [ ciMAX_OBSERVERS ];
	int       m_iNumObservers;

///////////////////////////////
// | Methods |
///////////////////////////////

	void clearObservers ();

};

#endif // !SUBJECT_H
