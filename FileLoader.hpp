/**************************************************************
* | FileLoader Class |
***************************************************************
*
*-------------------------------
* Description
* ------------------------------
* Defines several static methods for loading file formats
* from specified paths and returning them in usable formats.
*
***************************************************************
*
*-------------------------------
* Author
*-------------------------------
* Joeb Rogers
*
**************************************************************/

#ifndef FILELOADER_H
#define FILELOADER_H

///////////////////////////////
// | Headers |
///////////////////////////////

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class FileLoader
{

public:

///////////////////////////////
// | Constructor / Destructor |
/////////////////////////////// 

	 FileLoader ();
	~FileLoader ();

///////////////////////////////
// | Methods |
/////////////////////////////// 

	void         init      ( SDL_Renderer* pRenderer  );
	SDL_Texture* loadImage ( const std::string& sPath );

private:

///////////////////////////////
// | Variables |
///////////////////////////////

	bool          m_bInit;
	SDL_Renderer* m_pRenderer;

};

#endif // !FILELOADER_H
