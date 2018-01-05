#include "FileLoader.hpp"

FileLoader::FileLoader ()
	: m_bInit     ( false   )
	, m_pRenderer ( nullptr )
{
}

FileLoader::~FileLoader ()
{
	m_pRenderer = nullptr;
}

void FileLoader::init ( SDL_Renderer * pRenderer )
{
	if ( pRenderer == nullptr )
	{
		printf ( "FileLoader could not be initialised! Renderer is null.\n" );
	}

	m_bInit     = true;
	m_pRenderer = pRenderer;
}

SDL_Texture * FileLoader::loadImage ( const std::string & sPath )
{
	if ( !m_bInit )
	{
		printf ( "Unable to load image %s! FileLoader not initialised.\n" , sPath.c_str () );
		return nullptr;
	}

	//The final texture
	SDL_Texture* pTexture = nullptr;

	//Load image at specified path
	SDL_Surface* pSurface = IMG_Load ( sPath.c_str () );
	if ( pSurface == nullptr )
	{
		printf ( "Unable to load image %s! SDL_image Error: %s\n" , sPath.c_str () , IMG_GetError () );
	}
	else
	{
		//Create texture from surface pixels
		pTexture = SDL_CreateTextureFromSurface ( m_pRenderer , pSurface );
		if ( pTexture == NULL )
		{
			printf ( "Unable to create texture from %s! SDL Error: %s\n" , sPath.c_str () , SDL_GetError () );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface ( pSurface );
	}

	return pTexture;
}
