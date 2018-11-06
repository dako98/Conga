#include "Conga.h"
#include <stdexcept>

void CongaContainer::AddPerson(
	int lineID, const char* personName, const char* universityName)
{
	if (lineID >= linesCount)
	{
		throw std::out_of_range("Line does not exist!");
	}

	Student newElement = Student(personName, universityName);

	if (newElement.IsCompatibleWith(*lines[lineID].GetTail()))
	{
		lines[lineID].PushBack(newElement);
	}
	else
	{
		throw std::logic_error("Incompatible students.");
	}

}


