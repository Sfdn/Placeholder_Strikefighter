/**************************************************************
* | SpriteFactory Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Factory class to return complete sprite object from 
* parameters.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "FileLoader.hpp"
#include "Sprite.hpp"

class SpriteFactory
{

public:

///////////////////////////////
// | Methods |
/////////////////////////////// 

	static Sprite* createSprite  ();
	static Sprite* createSprite  ( SDL_Texture* pTexture    );
	static Sprite* createSprite  ( SDL_Texture* pTexture    , SDL_Rect& rect );
	static Sprite* createSprite  ( FileLoader*  pFileLoader , const std::string& sTextPath );
	static Sprite* createSprite  ( FileLoader*  pFileLoader , const std::string& sTextPath , SDL_Rect& rect );
								 
	static void    destroySprite ( Sprite* pSprite );

};

#endif // !SPRITEFACTORY_H
