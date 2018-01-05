#include "Transform.hpp"

Transform::Transform ()
	: m_vPosition ()
	, m_vRotation ()
	, m_vScale    ()
{
}

Transform::Transform ( const Vector3<float>& vPosition )
	: m_vPosition ( vPosition )
	, m_vRotation ()
	, m_vScale    ()
{
}

Transform::Transform ( const Vector3<float>& vPosition , const Vector3<float>& vRotation )
	: m_vPosition ( vPosition )
	, m_vRotation ( vRotation )
	, m_vScale    ()
{
}

Transform::Transform ( const Vector3<float>& vPosition , const Vector3<float>& vRotation , const Vector2<float>& vScale )
	: m_vPosition ( vPosition )
	, m_vRotation ( vRotation )
	, m_vScale    ( vScale    )
{
}

Transform::Transform ( const Transform & transform )
	: m_vPosition ( transform.getPosition () )
	, m_vRotation ( transform.getRotation () )
	, m_vScale    ( transform.getScale    () )
{
}

const Vector3<float>& Transform::getPosition () const
{
	return m_vPosition;
}

const Vector3<float>& Transform::getRotation () const
{
	return m_vRotation;
}

const Vector2<float>& Transform::getScale () const
{
	return m_vScale;
}

void Transform::setPosition ( const Vector3<float>& vPosition )
{
	m_vPosition = vPosition;
}

void Transform::setRotation ( const Vector3<float>& vRotation )
{
	m_vRotation = vRotation;
}

void Transform::setScale ( const Vector2<float>& vScale )
{
	m_vScale = vScale;
}

void Transform::move ( const float x , const float y )
{
	m_vPosition.x += x;
	m_vPosition.y += y;
}

void Transform::move ( const Vector2<float>& offset )
{
	m_vPosition.x += offset.x;
	m_vPosition.y += offset.y;
}
