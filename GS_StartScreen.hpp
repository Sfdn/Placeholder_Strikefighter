/**************************************************************
* | GS_StartScreen State |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This class represents the "start game" screen. It simply
* displays an image and moves on with player input.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GS_STARTGAME_H
#define GS_STARTGAME_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameState.hpp"
#include "SpriteFactory.hpp"
#include "ControlManager.hpp"
#include "SplashScreenBackground.hpp"
#include "Stopwatch.hpp"

class GS_StartGame: public GameState
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	        GS_StartGame  ();
	virtual ~GS_StartGame ();

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

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void setUpObjects ();

};

#endif // !GS_STARTGAME_H
