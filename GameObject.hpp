/**************************************************************
* | GameObject Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* The GameObject class defines a basic building block for any
* object within the game that will require the logic for both
* updating and rendering.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Updatable.hpp"
#include "Renderable.hpp"

class GameObject : public Updatable , public Renderable
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	virtual ~GameObject () {};

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void update () {};
	virtual void render () {};

};

#endif // !GAMEOBJECT_H
