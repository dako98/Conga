#ifndef _MENU_
#define _MENU_


#include <iostream>
#include <iomanip>
#include "CongaContainer.h"


const int MAX_COMMAND_LEN = 32;
const int MAX_NAME_LEN = 256;
const int MAX_UNI_LEN = 256;


enum COMMAND_ID
{
	INVALID = -1,

	APPEND, REMOVE_LAST, REMOVE_FIRST, REMOVE, MERGE, PRINT, QUIT,

	COMMANDS_COUNT
};

const char* COMMANDS[COMMANDS_COUNT] = {
	"append" ,
	"removeLast" ,
	"removeFirst" ,
	"remove" ,
	"merge" ,
	"print" ,
	"quit"
};

int ResolveID(const char* const string, const char** const list, int commandsCount)
{
	for (size_t i = 0; i < commandsCount; i++)
	{
		if (stricmp(string, list[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}


int GetLineID()
{
	int a = 0;

	std::cin >> a;
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return -1;
	}
	return a;
}

void FlushBuffer()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}



bool CommandParser(CongaContainer& target)
{


	char command[MAX_COMMAND_LEN];
	char name[MAX_NAME_LEN];
	char uni[MAX_UNI_LEN];
	int line1 = 0;
	int line2 = 0;

	std::cin >> std::setw(MAX_COMMAND_LEN) >> command;


	int commandID = ResolveID(command, COMMANDS, COMMANDS_COUNT);


	switch (commandID)
	{
	case INVALID:
		
		std::cout << "Invalid command.\n";
		FlushBuffer();


		break;
	case APPEND:

		std::cin >> std::setw(MAX_NAME_LEN) >> name;
		std::cin >> std::setw(MAX_UNI_LEN) >> uni;
		line1 = GetLineID();

		try
		{
			target.AddPerson(line1, name, uni);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << e.what() << std::endl;
			break;
		}
		catch (const std::logic_error& e)
		{
			std::cout << e.what() << std::endl;
			break;
		}
		std::cout << "Successfuly added \"" << name << "\" from \"" << uni << "\" to line " << line1 << '.' << std::endl;
		break;

	case REMOVE_LAST:


		line1 = GetLineID();

		try
		{
			target.RemoveLast(line1);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Invalid line ID.\n";
			break;
		}
		std::cout << "Successfuly removed the last person from line " << line1 << '.' << std::endl;

		break;
	case REMOVE_FIRST:

		line1 = GetLineID();

		try
		{
			target.RemoveFirst(line1);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Invalid line ID.\n";
			break;
		}
		std::cout << "Successfuly removed the first person from line " << line1 << '.' << std::endl;

		break;
	case REMOVE:

		std::cin >> std::setw(MAX_NAME_LEN) >> name;
		line1 = GetLineID();

		try
		{
			target.Remove(line1, name);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Invalid line ID.\n";
			break;
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what();
			break;
		}
		std::cout << "Successfuly removed \"" << name << "\" from line " << line1 << '.' << std::endl;


		break;
	case MERGE:

		line1 = GetLineID();
		line2 = GetLineID();


		try
		{
			target.Append(line1, line2);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Invalid line ID.\n" << std::endl;
			break;
		}
		catch (const std::logic_error& e)
		{
			std::cout << e.what() << std::endl;
			break;
		}
		std::cout << "Successfuly merged line " << line1 << " and line " << line2 << '.' << std::endl;

		break;
	case PRINT:

		target.Print();

		break;

	case QUIT:

		return false;

		break;

	default:
		break;
	}

	return true;
}






#endif // !_MENU_
