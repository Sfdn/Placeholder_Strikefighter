/**************************************************************
* | Updatable Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Updatable is an abstract virtual class defining that a
* particular class must implement a method for being updated
* by the system driving the application.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef UPDATABLE_H
#define UPDATABLE_H

class Updatable
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	virtual ~Updatable() {};

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void update () = 0;

};

#endif // !UPDATABLE_H
