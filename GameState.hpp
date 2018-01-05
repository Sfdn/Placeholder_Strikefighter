/**************************************************************
* | GameState Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Abstract class for all game states. Holds basic methods for
* driving game.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GAMESTATE_H
#define GAMESTATE_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <SDL.h>

///////////////////////////////
// | Forward Declarations |
///////////////////////////////

class InputManager;
class StateMachine;
class FileLoader;

class GameState
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         GameState ();
			 GameState ( InputManager* pInputManager );
			 GameState ( StateMachine* pStateMachine );
			 GameState ( InputManager* pInputManager , StateMachine* pStateMachine );
	virtual ~GameState ();

///////////////////////////////
// | Property Accessors |
/////////////////////////////// 

	void setInputManager ( InputManager* pInputManager );
	void setStateMachine ( StateMachine* pStateMachine );
	void setFileLoader   ( FileLoader*   pFileLoader   );
	void setRenderer     ( SDL_Renderer* pRenderer     );

///////////////////////////////
// | Methods |
/////////////////////////////// 

	virtual void enter        () = 0;
	virtual void handleEvents () = 0;
	virtual void update       () = 0;
	virtual void render		  () = 0;
	virtual void exit         () = 0;

///////////////////////////////
// | Variables |
/////////////////////////////// 

	InputManager* m_pInputManager;
	StateMachine* m_pStateMachine;
	FileLoader*   m_pFileLoader;
	SDL_Renderer* m_pRenderer;

};

#endif // !GAMESTATE_H
