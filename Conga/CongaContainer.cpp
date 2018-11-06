#include "CongaContainer.h"
#include <iostream>
#include <stdexcept>

void CongaContainer::AddPerson(
	int lineID, const char* personName, const char* universityName)
{

	if (lineID >= lines.GetSize())
	{
		throw std::out_of_range("Line does not exist!");
	}


	if (lineID == lines.GetSize())
	{
		List<Student> empty;
		lines.Pushback(empty);
	}

	Student newElement = Student(personName, universityName);

	if (lines[lineID].GetTail() != nullptr)
	{
		if (newElement.IsCompatibleWith(*lines[lineID].GetTail()))
		{
			lines[lineID].PushBack(newElement);
		}
		else
		{
			throw std::logic_error("Incompatible students.");
		}
	}
	else
	{
		lines[lineID].PushBack(newElement);
	}
}


CongaContainer::CongaContainer()
	:lines()
{
	List<Student> initial;

	lines.Pushback(initial);
}


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

void CongaContainer::DebugPrint() const
{
	size_t linesCount = lines.GetSize();

	for (size_t i = 0; i < linesCount; i++)
	{
		for (Student student : lines[i])
			student.DebugPrint();
		std::cout << "---------------";
	}
}
