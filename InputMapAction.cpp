#include "InputMapAction.hpp"

InputMapAction::InputMapAction ()
	:	eActionID         ( ACTION_INVALID )
	,   pButtonConfig     ( nullptr        )
	,   iNumButtonConfigs ( 0              )
{
}

InputMapAction::~InputMapAction ()
{
	if ( pButtonConfig != nullptr )
	{
		delete [] pButtonConfig;
		pButtonConfig = nullptr;
	}
}
