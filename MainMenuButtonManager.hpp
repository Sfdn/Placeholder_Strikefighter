/**************************************************************
* | MainMenuButtonManager Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Hardcoded class to position and handle interaction with the
* current main menu buttons.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef MAINMENUBUTTONMANAGER_H
#define MAINMENUBUTTONMANAGER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "MainMenuButton.hpp"
#include  <string>

class MainMenuButtonManager : public Entity
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	         MainMenuButtonManager ();
	virtual ~MainMenuButtonManager ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////



///////////////////////////////
// | Methods |
/////////////////////////////// 
	
	void init ( FileLoader* pFileLoader , SDL_Renderer * pRenderer );

	virtual void update   () override;
	virtual void render   () override;
	virtual void onNotify ( GameObject* pGameObject , const eEvent e ) override;

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	MainMenuButton* m_mainMenuButton;
	Vector3<float>* m_vButtonPositions;
	int             m_iCurrentButton;

	Sprite*         m_pConfirmDialogueBox;
	MainMenuButton* m_confirmBoxButton;
	Vector3<float>* m_vConfirmButtonPositions;
	int             m_iConfirmButton;
	
	bool            m_bShowConfirmBox;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void interact       ();
	void back           ();
	void moveSelectionX ( const int iDirection );
	void moveSelectionY ( const int iDirection );

};

#endif // !MAINMENUBUTTONMANAGER_H
