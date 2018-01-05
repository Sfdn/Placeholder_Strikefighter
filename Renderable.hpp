/**************************************************************
* | Renderable Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Renderable is an abstract virtual class defining that a 
* particular class must implement a method for drawing to the
* application window.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef RENDERABLE_H
#define RENDERABLE_H

///////////////////////////////
// | Headers |
///////////////////////////////

class Renderable
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	virtual ~Renderable() {};

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void render () = 0;

};

#endif // !RENDERABLE_H
