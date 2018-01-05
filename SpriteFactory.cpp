#include "SpriteFactory.hpp"

Sprite * SpriteFactory::createSprite ()
{
	return new Sprite;
}

Sprite * SpriteFactory::createSprite ( SDL_Texture * pTexture )
{
	Sprite* pSprite = new Sprite;
	pSprite->setTexture ( pTexture );
	return pSprite;
}

Sprite * SpriteFactory::createSprite ( SDL_Texture * pTexture , SDL_Rect & rect )
{
	Sprite* pSprite = new Sprite;
	pSprite->setTexture     ( pTexture );
	pSprite->setTextureRect ( rect );
	return pSprite;
}

Sprite * SpriteFactory::createSprite ( FileLoader* pFileLoader , const std::string & sTextPath )
{
	Sprite* pSprite = new Sprite;
	pSprite->setTexture ( pFileLoader->loadImage ( sTextPath ) );
	return pSprite;
}

Sprite * SpriteFactory::createSprite ( FileLoader* pFileLoader , const std::string & sTextPath , SDL_Rect & rect )
{
	Sprite* pSprite = new Sprite;
	pSprite->setTexture     ( pFileLoader->loadImage ( sTextPath ) );
	pSprite->setTextureRect ( rect );
	return pSprite;
}

void SpriteFactory::destroySprite ( Sprite * pSprite )
{
	delete pSprite;
	pSprite = nullptr;
}
