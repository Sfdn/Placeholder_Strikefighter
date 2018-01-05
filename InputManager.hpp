/**************************************************************
* | InputManager Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Processes raw input into usable actions.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <map>
#include <vector>
#include "Action.hpp"
#include "InputTypes.hpp"
#include "InputMapper.hpp"

class InputManager
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 InputManager ();
	~InputManager ();

///////////////////////////////
// | Property Accessors |
///////////////////////////////

	const std::vector<Action*>& getActions () const;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void createInputMap ( const std::string& sMapName );
	void removeInputMap ();
	void processAction  ( const SDL_Event& e , const int iInputType );
	void resetActions   ();
	void subscribe      ( Observer* pObserver , eActions eAction );
	void unsubscribe    ( Observer* pObserver , eActions eAction );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	std::map<const int , Action*> m_mapKeyboardActions;
	std::map<const int , Action*> m_mapMouseActions;
	std::map<const int , Action*> m_mapControllerButtonActions;
	std::map<const int , Action*> m_mapControllerAxisActions;

	std::vector<Action*> m_vPossibleActions;
	std::vector<Action*> m_vActiveActions;

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void createActions ();
	void deleteActions ();
	void clearVectors  ();
	void clearMaps     ();

	void mapActionToInput ( const InputMapAction& mapAction    );
	void mapButtonConfig  ( const ButtonConfig&   buttonConfig , Action* pAction );

	Action*                        retrieveActionFromID ( const eActions    eID );
	std::map<const int , Action*>* retrieveMapFromID    ( const eInputTypes eID );

	Action* getKeyboardAction         ( const SDL_Event& e ) const;
	Action* getControllerButtonAction ( const SDL_Event& e ) const;
	Action* getControllerAxisAction   ( const SDL_Event& e ) const;

	const float normaliseAxisValue ( const int iVal ) const;

};

#endif // !INPUTMANAGER_H
