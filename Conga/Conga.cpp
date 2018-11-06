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


CongaContainer::CongaContainer()
	:linesCount(0)
	, lines()
{ }


void CongaContainer::RemoveLast(int lineID)
{
	lines[lineID].PopBack();

	if (lines[lineID].begin()==nullptr)
	{
		lines.Remove(lineID);
	}
}

void CongaContainer::RemoveFirst(int lineID)
{
	lines[lineID].PopFront();

	if (lines[lineID].begin() == nullptr)
	{
		lines.Remove(lineID);
	}
}