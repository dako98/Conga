#include <iostream>
#include <stdexcept>
#include "Student.h"
#include "UniversityIDs.h"

//Throws std::bad_alloc.
//Throws std::invalid_argument for unknown university.
Student::Student(const char* name, const char* universityName)
	:name(nullptr)
	,universityCode(INVALID)
{

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	for (size_t i = 0; i < UNIVERSITYS_COUNT; i++)
	{
		if (stricmp(UNIVERSITY_NAMES[i], universityName) == 0)
		{
			universityCode = i;
			break;
		}
	}

	if (universityCode == INVALID)
	{
		throw std::invalid_argument("University is not in the list.");
	}
}

void Student::Print() const
{
	std::cout << "(" << name << ", " << UNIVERSITY_NAMES[universityCode] << ")";
}

//Throws std::bad_alloc.
void Student::Copy(const Student &other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	universityCode = other.universityCode;

}

Student::Student(const Student &other)
{
	Copy(other);
}

Student& Student::operator=(const Student &other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

Student::~Student()
{
	Clear();
}

void Student::Clear()
{
	delete[] name;
	name = nullptr;

	universityCode = INVALID;
}


bool Student::IsCompatibleWith(const Student &other) const
{

	for (size_t i = 0; UNIVERSITY_FRIENDSHIPS[universityCode][i] != INVALID ; i++)
	{
		if (other.universityCode == UNIVERSITY_FRIENDSHIPS[universityCode][i])
		{
			return true;
		}
	}
	return false;
}

const char* const Student::GetName() const
{
	return name;
}
