/**************************************************************
* | InputMapper Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Parses .inputmap files into data structures usable by the
* Input Manager.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef INPUTMAPPER_H
#define INPUTMAPPER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Constants.hpp"
#include "InputMap.hpp"

class InputMapper
{

public:

///////////////////////////////
// | Static Methods |
/////////////////////////////// 

	static InputMap* createInputMap ( const std::string& sFilename );

private:

///////////////////////////////
// | Methods |
/////////////////////////////// 

	static void      createMappedAction ( std::vector<std::string>::iterator& it , InputMap* pInputMap         , const int iIndex );
	static void      createButtonConfig ( std::vector<std::string>::iterator& it , InputMapAction& inputAction , const int iIndex );
	static const int getID              ( std::vector<std::string>::iterator& it , const char cStart           , const char cEnd  );

};

#endif // !INPUTMAPPER_H
