/**************************************************************
* | SplashScreenBackground Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Temporary class to control the splash screen backgrounds.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef SPLASHSCREENBACKGROUND_H
#define SPLASHSCREENBACKGROUND_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "SpriteFactory.hpp"

class SplashScreenBackground : public Entity
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         SplashScreenBackground ();
	virtual ~SplashScreenBackground ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	void setSprite ( Sprite* pSprite );

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void onNotify ( GameObject* pGameObject , const eEvent e );
	virtual void update   ();
	virtual void render   ();
						  
private:

///////////////////////////////
// | Variables |
///////////////////////////////

	Sprite* m_pSprite;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void interact ();

};

#endif // !SPLASHSCREENBACKGROUND_H
