/**************************************************************
* | Game Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Wrapper for the main game loop. Inits SDL2, polls the 
* event loop and runs the state machine.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef GAME_H
#define GAME_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "StateMachine.hpp"
#include "FileLoader.hpp"

class Game
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 Game ();
	~Game ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	SDL_Renderer* getRenderer     () const;
	StateMachine* getStateMachine () const;
	FileLoader*   getFileLoader   () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void Run ();

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	//The window we'll be rendering to
	SDL_Window*   m_pWindow;
	//The renderer for the window
	SDL_Renderer* m_pRenderer;
	//The statemachine running the core update loop for the game.
	StateMachine* m_pStateMachine;
	//The fileloader to load and convert external files.
	FileLoader*   m_pFileLoader;

	///////////////

	bool m_bQuit;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	bool init  ();
	void close ();
};

#endif // !GAME_H
