#include "CongaContainer.h"
#include <iostream>
#include <stdexcept>

//Throws std::out_of_range if line does not exist.
//Throws std::logic_error when new person is incompatible.
void CongaContainer::AddPerson(
	int lineID, const char* personName, const char* universityName)
{

	if (lineID >= lines.GetSize())
	{
		throw std::out_of_range("Line does not exist.");
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
	:lines(true)
{
	List<Student> initial;

	lines.Pushback(initial);
}

//Throws std::out_of_range if line does not exist.
void CongaContainer::RemoveLast(int lineID)
{
	lines[lineID].PopBack();

	if (lines[lineID].begin() == nullptr)
	{
		lines.Remove(lineID);
	}
}

//Throws std::out_of_range if line does not exist.
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
		std::cout << "---------------\n";
	}
}


//Fix " - " after last element.
void CongaContainer::Print() const
{
	size_t linesCount = lines.GetSize();

	for (size_t i = 0; i < linesCount; i++)
	{
		std::cout << "Line " << i << ": ";

		for (Student student : lines[i])
		{
			student.Print();

			std::cout << " - ";
		}
		std::cout << '\n';
	}
}

//Throws std::out_of_range for invalid lineID.
//Throws std::invalid_argument for invalid name.
void CongaContainer::Remove(int lineID, const char* name)
{
	List<Student>::Iterator element(lines[lineID].begin());

	List<Student> newList;

	for (Student &st : lines[lineID])
	{
		if (stricmp(element->GetName(), name) == 0)
		{
			newList = lines[lineID].SplitAfter(element);
			lines[lineID].PopBack();
			break;
		}
		++element;
	}

	if (newList.begin() != nullptr)
	{
		lines.Pushback(newList);
	}
	else
	{
		throw std::invalid_argument("Invalid name.");
	}
}

//Throws std::logic_error if lines are incompatible.
//Throws std::out_of_range if invalid lineIDs.
void CongaContainer::Append(int line1, int line2)
{
	if (line1 != line2)
	{
		if (lines[line2].begin()->IsCompatibleWith(*lines[line1].GetTail()) == false)
		{
			throw std::logic_error("Incompatible students.");
		}

		lines[line1].Append(lines[line2]);

		lines.Remove(line2);
	}
}