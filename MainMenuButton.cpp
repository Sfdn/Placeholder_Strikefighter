#include "MainMenuButton.hpp"

MainMenuButton::MainMenuButton ()
	: m_pSprite  ( nullptr )
	, m_bActive  ( false   )
	, m_bPressed ( false   )
{
}

MainMenuButton::~MainMenuButton ()
{
	if ( m_pSprite != nullptr )
	{
		SpriteFactory::destroySprite ( m_pSprite );
	}
}

void MainMenuButton::setSprite ( Sprite * pSprite )
{
	m_pSprite = pSprite;
}

void MainMenuButton::setActive ( const bool bActive )
{
	m_bActive = bActive;
}

const bool MainMenuButton::getPressed () const
{
	return m_bPressed;
}

Sprite * MainMenuButton::getSprite () const
{
	return m_pSprite;
}

void MainMenuButton::render ()
{
	if ( !m_bActive )
	{
		return;
	}

	if ( m_pSprite != nullptr )
	{
		m_pSprite->render ();
	}
}

void MainMenuButton::interact ()
{
	m_bPressed = true;
}
