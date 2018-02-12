/**************************************************************
* | Sprite Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Basic static sprite class. Inherits from entity, with the 
* addition of a texture.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef SPRITE_H
#define SPRITE_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Entity.hpp"

class Sprite : public Transform , public GameObject
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	          Sprite ();
	 virtual ~Sprite () {};

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	void setRenderer    ( SDL_Renderer* pRenderer );
	void setTexture     ( SDL_Texture*  pTexture  );
	void setTexture     ( SDL_Texture*  pTexture  , SDL_Rect& rect );
	void setTextureRect ( SDL_Rect&     rect      );

	const int getWidth  () const;
	const int getHeight () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void render      () override;
			void renderFlip  ( SDL_RendererFlip flip );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	SDL_Texture*  m_pTexture;
	SDL_Rect      m_textRect;
	SDL_Renderer* m_pRenderer;

	int           m_iWidth;
	int           m_iHeight;

///////////////////////////////
// | Methods |
/////////////////////////////// 



};

#endif // !_H
