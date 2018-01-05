/**************************************************************
* | Transform Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* A basic transform utility to hold data for position, rotation
* and scale, as well as manipulate those values.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef TRANSFORM_H
#define TRANSFORM_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Vector2.hpp"
#include "Vector3.hpp"

class Transform
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 Transform  ();
	 Transform  ( const Vector3<float>& vPosition );
	 Transform  ( const Vector3<float>& vPosition , const Vector3<float>& vRotation );
	 Transform  ( const Vector3<float>& vPosition , const Vector3<float>& vRotation , const Vector2<float>& vScale );
	 Transform  ( const Transform& transform );
	 ~Transform () {};

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	const Vector3 <float> & getPosition () const;
	const Vector3 <float> & getRotation () const;
	const Vector2 <float> & getScale    () const;

	void setPosition ( const Vector3<float>& vPosition );
	void setRotation ( const Vector3<float>& vRotation );
	void setScale    ( const Vector2<float>& vScale    );

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void move ( const float x , const float y );
	void move ( const Vector2<float>& offset  );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	Vector3<float> m_vPosition;
	Vector3<float> m_vRotation;
	Vector2<float> m_vScale;

///////////////////////////////
// | Methods |
/////////////////////////////// 



};

#endif // !TRANSFORM_H
