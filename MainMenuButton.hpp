/**************************************************************
* | MainMenuButton Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Basic button class to react to input and display correctly.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef MAINMENUBUTTON_H
#define MAINMENUBUTTON_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "Entity.hpp"
#include "SpriteFactory.hpp"

class MainMenuButton
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         MainMenuButton ();
	virtual ~MainMenuButton ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	void setSprite ( Sprite* pSprite    );
	void setActive ( const bool bActive );

	const bool getPressed () const;
	Sprite*    getSprite  () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void render ();

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	Sprite* m_pSprite;
	bool    m_bActive;
	bool    m_bPressed;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void interact ();

};

#endif // !MAINMENUBUTTON_H
