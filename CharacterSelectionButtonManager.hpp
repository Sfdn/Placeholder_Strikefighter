/**************************************************************
* | CharacterSelectionButtonManager Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Hardcoded class to position and handle interaction with the
* current character selection options.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef CHARACTERSELECTIONBUTTONMANAGER_H
#define CHARACTERSELECTIONBUTTONMANAGER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include "MainMenuButton.hpp"
#include  <string>

class CharacterSelectionButtonManager : public Entity
{

public:

	///////////////////////////////
	// | Constructor / Destructor |
	/////////////////////////////// 

	         CharacterSelectionButtonManager ();
	virtual ~CharacterSelectionButtonManager ();

	///////////////////////////////
	// | Property Accessors |
	///////////////////////////////

	const int  getSelection () const;
	const bool getSelected  () const;
	
	void setButtonSize ( float fW , float fH );

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void init ( FileLoader* pFileLoader , SDL_Renderer * pRenderer , ePlayers ePlayer );

	virtual void update   () override;
	virtual void render   () override;
	virtual void onNotify ( GameObject* pGameObject , const eEvent e ) override;

private:

	///////////////////////////////
	// | Variables |
	///////////////////////////////

	MainMenuButton* m_mainMenuButton;
	Vector3<float>* m_vButtonPositions;
	float           m_fButtonWidth;
	float           m_fButtonHeight;
	int             m_iCurrentButton;

	int             m_iSelection;
	bool            m_bSelected;

	///////////////////////////////
	// | Methods |
	/////////////////////////////// 

	void interact       ();
	void back           ();
	void moveCursor     ( const Action* action );
	void moveSelectionX ( const int iDirection );
	void moveSelectionY ( const int iDirection );

};

#endif // !CHARACTERSELECTIONBUTTONMANAGER_H
