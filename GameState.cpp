#include "GameState.hpp"

GameState::GameState ()
	: m_pInputManager ( nullptr )
	, m_pStateMachine ( nullptr )
	, m_pFileLoader   ( nullptr )
	, m_pRenderer     ( nullptr )
{
}

GameState::GameState ( InputManager * pInputManager )
	: m_pInputManager ( pInputManager )
	, m_pStateMachine ( nullptr       )
{
}

GameState::GameState ( StateMachine * pStateMachine )
	: m_pInputManager ( nullptr       )
	, m_pStateMachine ( pStateMachine )
{
}

GameState::GameState ( InputManager * pInputManager , StateMachine * pStateMachine )
	: m_pInputManager ( pInputManager )
	, m_pStateMachine ( pStateMachine )
{
}

GameState::~GameState ()
{
	m_pInputManager = nullptr;
	m_pStateMachine = nullptr;
}

void GameState::setInputManager ( InputManager * pInputManager )
{
	m_pInputManager = pInputManager;
}

void GameState::setStateMachine ( StateMachine * pStateMachine )
{
	m_pStateMachine = pStateMachine;
}

void GameState::setFileLoader ( FileLoader * pFileLoader )
{
	m_pFileLoader = pFileLoader;
}

void GameState::setRenderer ( SDL_Renderer * pRenderer )
{
	m_pRenderer = pRenderer;
}
