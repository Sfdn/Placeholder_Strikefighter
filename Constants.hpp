/**************************************************************
* | Constants |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Holds all the global constant variables.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef CONSTANTS_H
#define CONSTANTS_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <iostream>
#include "Vector3.hpp"

///////////////////////////////
// | Ints |
///////////////////////////////

#pragma region Const Ints

//Error codes
const int ciERROR_NOT_FOUND = -1;

//Screen dimension constants
const int ciSCREEN_WIDTH  = 1366;
const int ciSCREEN_HEIGHT = 768;

//Frame rate
const int ciMS_FRAME_TIME = static_cast< int >( 1000 / 60 );

//Axis defines
const int ciAXIS_X = 0;
const int ciAXIS_Y = 1;

//Axis ranges
const int ciAXIS_MAX = 32767;
const int ciAXIS_MIN = -32768;

//Observers
const int ciMAX_OBSERVERS = 5;

//Splash Screen
const int ciSPLASH_0_WAIT_TIME            = 3000;
const int ciSPLASH_1_WAIT_TIME            = 3000;
const int ciVIDEO_INTRO_WAIT_TIME         = 3000;
const int ciCHARACTER_SELECTION_WAIT_TIME = 60000;

//Main Menu
const int ciNumMenuButtons    = 6;
const int ciNumConfirmButtons = 2;

//Character Selection Screen
const int ciNUM_CHARACTERS     = 12;


#pragma endregion Const Ints

///////////////////////////////
// | Strings |
///////////////////////////////

#pragma region Const Strings

//Paths
const std::string csINPUT_MAP_PATH      = "Input/";
const std::string csTEXTURE_PATH        = "Textures/";

//Extensions
const std::string csINPUT_MAP_EXTENSION = ".inputmap";
const std::string csIMAGE_EXTENSION     = ".png";

//Texture Names
const std::string csSPLASH_SCREEN_0         = "SplashScreen_0";
const std::string csSPLASH_SCREEN_1         = "SplashScreen_1";
const std::string csVIDEO_INTRO             = "VideoIntro_0";
const std::string csSTART_GAME_SCREEN       = "LandingMenu_0";
const std::string csMAIN_MENU_SCREEN        = "MainMenu_0";
const std::string csCHARACTER_SELECT_SCREEN = "CharacterSelect_0";

const std::string csMAIN_MENU_SELECTOR    = "mm_Selector";
const std::string csMAIN_MENU_SELECTOR_0  = "mm_Exit1";
const std::string csMAIN_MENU_SELECTOR_1  = "mm_Exit2";
const std::string csMAIN_MENU_SELECTOR_2  = "mm_Exit3";
const std::string csMAIN_MENU_SELECTOR_3  = "mm_Exit4";
const std::string csMAIN_MENU_SELECTOR_4  = "mm_Exit5";
const std::string csMAIN_MENU_SELECTOR_5  = "mm_Exit6";
const std::string csMAIN_MENU_CONFIRM_BOX = "mm_ConfirmBox";

const std::string csCHARACTER_SELECTOR_0  = "css_Player1Selector";
const std::string csCHARACTER_SELECTOR_1  = "css_Player2Selector";
//Character currently needs to be 409px x 394px
const std::string csCHARACTER             = "css_Character";
//Timer numbers							 
const std::string csNUMBERS               = "Numbers/";


#pragma endregion Const Strings

///////////////////////////////
// | Chars |
///////////////////////////////

#pragma region Const Chars

//Input Map Parsing
const char ccIM_DELIM        = ':';
const char ccIM_HEAD_START   = '[';
const char ccIM_HEAD_END     = ']';
const char ccIM_ACTION_DELIM = '*';
const char ccIM_NEWLINE      = '\n';

#pragma endregion Const Chars

///////////////////////////////
// | Vectors |
///////////////////////////////

#pragma region Const Vectors

//Portrait Positions
const Vector3<float> cvCHARACTER_PORTRAIT_P1 = { 32.0f  , 85.0f , 0.0f };
const Vector3<float> cvCHARACTER_PORTRAIT_P2 = { 925.0f , 85.0f , 0.0f };

#pragma endregion Const Vectors

#endif // !CONSTANTS_H
