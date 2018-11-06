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
{ }

CongaContainer::CongaContainer(const CongaContainer &other)
{
	Copy(other);
}

CongaContainer::CongaContainer& operator=(const CongaContainer &other)
{
	if (this!=&other)
	{
		Clear();
		Copy();
	}
	return *this;
}

CongaContainer::~CongaContainer()
{
	Clear();
}