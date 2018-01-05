#include "InputMapper.hpp"

InputMap* InputMapper::createInputMap ( const std::string & sFilename )
{
	//Load specified input map file.
	std::ifstream inFile ( csINPUT_MAP_PATH + sFilename + csINPUT_MAP_EXTENSION );

	//Create an inputmap object to populate with the parsed data.
	InputMap*                pParsedInput = new InputMap;
	//For storing all lines in the file.
	std::vector<std::string> vLines;
	//For populating with the current parsed line.
	std::string              sLine;

	//Loop through all the lines in the file
	while ( std::getline ( inFile , sLine ) )
	{
		//Insert all lines into the vector for proper parsing.
		vLines.push_back ( sLine );

		//If the current line denotes the end of an action, increase the current action counter.
		if ( sLine [ 0 ] == ccIM_ACTION_DELIM )
		{
			pParsedInput->iNumMappedActions++;
		}
	}

	//Create the InputMapActions based on the number of counted actions.
	pParsedInput->pMappedAction = new InputMapAction [ pParsedInput->iNumMappedActions ];
	//Set up an iterator to properly parse the lines into actions.
	std::vector<std::string>::iterator it = vLines.begin ();

	//Loop through the array and set up the action objects inside.
	for ( int i = 0; i < pParsedInput->iNumMappedActions; i++ )
	{
		createMappedAction ( it , pParsedInput , i );
	}
	
	//Return the parsed input map.
	return pParsedInput;
}

void InputMapper::createMappedAction ( std::vector<std::string>::iterator& it , InputMap* pInputMap , const int iIndex )
{
	//Store reference for shorthand use.
	InputMapAction& action = pInputMap->pMappedAction [ iIndex ];
	//Get the action ID for this action and convert it to the proper enum format.
	action.eActionID       = static_cast< eActions >( getID ( it , ccIM_DELIM , ccIM_HEAD_END ) );
	//We can increment the iterator as we're finished with the action header.
	++it;

	//Count how many lines we loop through so we can return the iterator to this start point later.
	int iCyclesCounted = 0;
	//Loop until we reach the end of the action.
	while ( ( *it ) [ 0 ] != ccIM_ACTION_DELIM )
	{
		//Incrememnt the number of button configs every time we find a header character.
		if ( ( *it ) [ 0 ] == ccIM_HEAD_START )
		{
			action.iNumButtonConfigs++;
		}
		++it;
		iCyclesCounted++;
	}

	//Instantiate the array of button configs based on the input types counted.
	action.pButtonConfig = new ButtonConfig [ action.iNumButtonConfigs ];
	//Set the iterator back to the start point.
	it -= iCyclesCounted;

	//Loop through the array of button configs and set them up.
	for ( int i = 0; i < action.iNumButtonConfigs; i++ )
	{
		createButtonConfig ( it , action , i );
	}
	++it;
}

void InputMapper::createButtonConfig ( std::vector<std::string>::iterator& it , InputMapAction& inputAction , const int iIndex )
{
	//Store reference for shorthand.
	ButtonConfig& buttonConfig = inputAction.pButtonConfig [ iIndex ];
	//Get the enum ID and convert it to the correct type.
	buttonConfig.eInputTypeID  = static_cast< eInputTypes >( getID ( it , ccIM_DELIM , ccIM_HEAD_END ) );
	//Increment the iterator as we're done with the header.
	++it;

	//Loop through until we reach the next header or the end of the action.
	while ( ( *it ) [ 0 ] != ccIM_HEAD_START && ( *it ) [ 0 ] != ccIM_ACTION_DELIM )
	{
		buttonConfig.iNumButtons++;
		++it;
	}

	//Instantiate the array of buttons.
	buttonConfig.piButtonID = new int [ buttonConfig.iNumButtons ];
	//Reset the iterator back to the first button.
	it -= buttonConfig.iNumButtons;

	//Loop through the buttons.
	for ( int i = 0; i < buttonConfig.iNumButtons; i++ , ++it )
	{
		//Get the input specific button ID.
		buttonConfig.piButtonID [ i ] = getID ( it , ccIM_DELIM , ccIM_NEWLINE );
	}
}

const int InputMapper::getID ( std::vector<std::string>::iterator & it , const char cStart , const char cEnd )
{
	//Find the start of the ID based on the specified delimiter character.
	size_t iStart = ( *it ).find ( cStart ) + 1;
	//Find the number of characters needed to substr between the ID start and the end character.
	size_t iCount = ( *it ).find ( cEnd ) - iStart;

	//Return the substring as an int.
	return stoi ( ( *it ).substr ( iStart , iCount ) );
}
