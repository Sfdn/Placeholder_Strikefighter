/**************************************************************
* | GS_VideoIntro State |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This class represent the video intro for the game. Acts in 
* a similar manner to the splash screens, but with the addition
* of streamed media.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GS_VIDEOINTRO_H
#define GS_VIDEOINTRO_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameState.hpp"
#include "SpriteFactory.hpp"
#include "ControlManager.hpp"
#include "SplashScreenBackground.hpp"
#include "Stopwatch.hpp"

class GS_VideoIntro : public GameState
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	         GS_VideoIntro ();
	virtual ~GS_VideoIntro ();

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

#endif // !GS_VIDEOINTRO_H
