/**************************************************************
* | Vector2 Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* A generic Vector2 utility to store a pair of coordinates.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef VECTOR2_H
#define VECTOR2_H

///////////////////////////////
// | Headers |
///////////////////////////////


template <class T> 
struct Vector2
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	Vector2 ();
	Vector2 ( const T& tX , const T& tY );
	virtual ~Vector2 () {};

///////////////////////////////
// | Variables |
///////////////////////////////

	T x;
	T y;
	
///////////////////////////////
// | Methods |
/////////////////////////////// 



};

template<class T>
inline Vector2<T>::Vector2 ()
	: x ( 0 )
	, y ( 0 )
{
}

template<class T>
inline Vector2<T>::Vector2 ( const T & tX , const T & tY )
	: x ( tX )
	, y ( tY )
{
}

#endif // !VECTOR2_H