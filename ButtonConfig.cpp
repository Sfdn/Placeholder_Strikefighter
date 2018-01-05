#include "ButtonConfig.hpp"

ButtonConfig::ButtonConfig ()
	: eInputTypeID ( INPUTTYPE_NULL )
	, piButtonID   ( nullptr        )
	, iNumButtons  ( 0              )
{
}

ButtonConfig::~ButtonConfig ()
{
	if ( piButtonID != nullptr )
	{
		delete [] piButtonID;
		piButtonID = nullptr;
	}
}
