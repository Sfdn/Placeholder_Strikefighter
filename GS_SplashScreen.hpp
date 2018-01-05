/**************************************************************
* | GS_SplashScreen State |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This class represents the first splash screen gamestate.
* The state draws an image and moves on after a set amount of 
* time.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GS_SPLASHSCREEN_H
#define GS_SPLASHSCREEN_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameState.hpp"
#include "SpriteFactory.hpp"
#include "ControlManager.hpp"
#include "SplashScreenBackground.hpp"
#include "Stopwatch.hpp"

class GS_SplashScreen : public GameState
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         GS_SplashScreen ();
	virtual ~GS_SplashScreen ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////



///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void enter        () override;
	virtual void handleEvents () override;
	virtual void update       () override;
	virtual void render       () override;
	virtual void exit         () override;


private:

///////////////////////////////
// | Variables |
///////////////////////////////

	SDL_Event               m_e;
	SplashScreenBackground* m_pBackground;
	Stopwatch               m_stopwatch;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void setUpObjects ();

};

#endif // !GS_SPLASHSCREEN_H
