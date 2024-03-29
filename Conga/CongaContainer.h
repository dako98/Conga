#ifndef _CONGA_CONTAINER_
#define _CONGA_CONTAINER_

#include "DoubleList.h"
#include "DynamicArray.h"
#include "Student.h"

class CongaContainer
{

public:


	CongaContainer();

	//Throws std::out_of_range if line does not exist.
	//Throws std::logic_error when new person is incompatible.
	//Throws std::bad_alloc if not enough memory.
	void AddPerson(int lineID, const char* personName,
		const char* universityName);

	//Throws std::out_of_range if line does not exist.
	void RemoveLast(int lineID);
	//Throws std::out_of_range if line does not exist.
	void RemoveFirst(int lineID);

	void Print() const;

	//Throws std::out_of_range if line does not exist.
	//Throws std::bad_alloc if not enough memory.
	void Remove(int lineID, const char* name);

	//Throws std::logic_error if lines are incompatible.
	//Throws std::out_of_range if invalid lineIDs.
	void Append(int line1, int line2);



private:

	DynArray<List<Student>> lines;

};



#endif // !_CONGA_CONTAINER_
