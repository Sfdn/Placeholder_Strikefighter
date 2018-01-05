#include "Game.hpp"

Game::Game ()
	: m_pWindow		  ( NULL  )
	, m_pRenderer     ( NULL  )
	, m_pStateMachine ( nullptr )
	, m_pFileLoader   ( nullptr )
	, m_bQuit		  ( false   )
{

}

Game::~Game ()
{
	close ();
}

SDL_Renderer * Game::getRenderer () const
{
	return m_pRenderer;
}

StateMachine * Game::getStateMachine () const
{
	return m_pStateMachine;
}

FileLoader * Game::getFileLoader () const
{
	return m_pFileLoader;
}

void Game::Run ()
{
	if ( !init () )
	{
		printf ( "Failed to initialize game!\n" );
	}
	else
	{
		m_pStateMachine->init        ( GAMESTATE_SPLASHSCREEN_0 );
		while ( m_pStateMachine->update () ) {};
	}
}

bool Game::init ()
{
	//Initialization flag
	bool bSuccess { true };

	//Initialize SDL
	if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER ) < 0 )
	{
		printf ( "SDL could not initialize! SDL Error: %s\n" , SDL_GetError () );
		bSuccess = false;
	}
	else
	{
		//Create window
		m_pWindow = SDL_CreateWindow ( "Seifedin Engine" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , ciSCREEN_WIDTH , ciSCREEN_HEIGHT , SDL_WINDOW_SHOWN );
		if ( m_pWindow == NULL )
		{
			printf ( "Window could not be created! SDL Error: %s\n" , SDL_GetError () );
			bSuccess = false;
		}
		else
		{
			//Create renderer for window
			m_pRenderer = SDL_CreateRenderer ( m_pWindow , -1 , SDL_RENDERER_ACCELERATED );
			if ( m_pRenderer == NULL )
			{
				printf ( "Renderer could not be created! SDL Error: %s\n" , SDL_GetError () );
				bSuccess = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor ( m_pRenderer , 0xFF , 0xFF , 0xFF , 0xFF );

				//Initialize PNG loading
				int iImgFlags = IMG_INIT_PNG;
				if ( !( IMG_Init ( iImgFlags ) & iImgFlags ) )
				{
					printf ( "SDL_image could not initialize! SDL_image Error: %s\n" , IMG_GetError () );
					bSuccess = false;
				}
				else
				{
					//Instantiate other objects
					m_pFileLoader   = new FileLoader;
					m_pStateMachine = new StateMachine ( m_pFileLoader , m_pRenderer );

					m_pFileLoader->init ( m_pRenderer );
				}
			}			
		}
	}

	return bSuccess;
}

void Game::close ()
{
	//Destroy window
	SDL_DestroyWindow ( m_pWindow );
	m_pWindow = nullptr;

	//Destroy renderer
	SDL_DestroyRenderer ( m_pRenderer );
	m_pRenderer = nullptr;

	delete m_pStateMachine;
	m_pStateMachine = nullptr;

	delete m_pFileLoader;
	m_pFileLoader = nullptr;

	//Quit SDL subsystems
	SDL_Quit ();
}
