/**************************************************************
* | GS_MainMenu State |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* This class represent the main menu for the game. Acts as a
* hub for controlling which state is going to be accessed next.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GS_MAINMENU_H
#define GS_MAINMENU_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "GameState.hpp"
#include "SpriteFactory.hpp"
#include "ControlManager.hpp"
#include "SplashScreenBackground.hpp"
#include "MainMenuButtonManager.hpp"

class GS_MainMenu : public GameState
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	         GS_MainMenu ();
	virtual ~GS_MainMenu ();

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
	Sprite*                 m_pBackground;
	MainMenuButtonManager   m_buttonManager;

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void setUpObjects ();

};

#endif // !GS_MAINMENU_H
