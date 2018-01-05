/**************************************************************
* | Vector3 Struct |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* A generic Vector3 utility to store a tuple of coordinates.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef VECTOR3_H
#define VECTOR3_H

///////////////////////////////
// | Headers |
///////////////////////////////


template <class T>
struct Vector3
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	Vector3 ();
	Vector3 ( const T& tX , const T& tY , const T& tZ );
	virtual ~Vector3 () {};

	///////////////////////////////
	// | Variables |
	///////////////////////////////

	T x;
	T y;
	T z;

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 



};

template<class T>
inline Vector3<T>::Vector3 ()
	: x ( 0 )
	, y ( 0 )
	, z ( 0 )
{
}

template<class T>
inline Vector3<T>::Vector3 ( const T & tX , const T & tY , const T & tZ )
	: x ( tX )
	, y ( tY )
	, z ( tZ )
{
}

#endif // !VECTOR3_H
