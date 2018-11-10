#include <iostream>
#include "CongaContainer.h"
#include "Student.h"
#include "Menu.h"


int main()
{
	CongaContainer test;

	bool running = true;

	while (running)
	{
		running = CommandParser(test);
	}

	return 0;
}