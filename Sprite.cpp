#include "Sprite.hpp"

Sprite::Sprite ()
	: m_pTexture  ( nullptr )
	, m_textRect  ()
	, m_pRenderer ( nullptr )
	, m_iWidth    ( 0       )
	, m_iHeight   ( 0       )
{
}

void Sprite::setRenderer ( SDL_Renderer * pRenderer )
{
	m_pRenderer = pRenderer;
}

void Sprite::setTexture ( SDL_Texture * pTexture )
{
	m_pTexture = pTexture;
	SDL_QueryTexture ( m_pTexture , NULL , NULL , &m_iWidth , &m_iHeight );
}

void Sprite::setTexture ( SDL_Texture * pTexture , SDL_Rect & rect )
{
	m_pTexture = pTexture;
	m_textRect = rect;
	SDL_QueryTexture ( m_pTexture , NULL , NULL , &m_iWidth , &m_iHeight );
}

void Sprite::setTextureRect ( SDL_Rect & rect )
{
	m_textRect = rect;
}

const int Sprite::getWidth () const
{
	return m_iWidth;
}

const int Sprite::getHeight () const
{
	return m_iHeight;
}

SDL_Texture * Sprite::getTexture () const
{
	return m_pTexture;
}

void Sprite::render ()
{
	if ( m_pTexture == nullptr ) { return; }

	SDL_Rect rect;
	Vector3<float> v = getPosition ();
	rect.w           = m_iWidth;
	rect.h           = m_iHeight;
	rect.x           = v.x;
	rect.y           = v.y;
	SDL_RenderCopy ( m_pRenderer , m_pTexture , NULL , &rect );
}

void Sprite::renderFlip ( SDL_RendererFlip flip )
{
	if ( m_pTexture == nullptr ) { return; }

	SDL_Rect rect;
	Vector3<float> v = getPosition ();
	rect.w           = m_iWidth;
	rect.h           = m_iHeight;
	rect.x           = v.x;
	rect.y           = v.y;
	SDL_RenderCopyEx ( m_pRenderer 
					   , m_pTexture 
					   , NULL 
					   , &rect 
					   , 0
					   , NULL 
					   , flip 
	);
}
