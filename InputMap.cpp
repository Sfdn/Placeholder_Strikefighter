#include "InputMap.hpp"

InputMap::InputMap ()
	: pMappedAction     ( nullptr )
	, iNumMappedActions ( 0       )
{
}

InputMap::~InputMap ()
{
	if ( pMappedAction != nullptr )
	{
		delete [] pMappedAction;
		pMappedAction = nullptr;
	}
}
