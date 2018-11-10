#ifndef _CONGA_CONTAINER_
#define _CONGA_CONTAINER_

//#include "List.h"
#include "DoubleList.h"
#include "DynamicArray.h"
#include "Student.h"

class CongaContainer
{

public:


	CongaContainer();

	//Throws std::out_of_range if line does not exist.
	//Throws std::logic_error when new person is incompatible.
	void AddPerson(int lineID, const char* personName,
		const char* universityName);

	//Throws std::out_of_range if line does not exist.
	void RemoveLast(int lineID);
	//Throws std::out_of_range if line does not exist.
	void RemoveFirst(int lineID);

	void Print() const;

	//Throws std::out_of_range if line does not exist.
	void Remove(int lineID, const char* name);

	//Throws std::logic_error if lines are incompatible.
	//Throws std::out_of_range if invalid lineIDs.
	void Append(int line1, int line2);

	void DebugPrint() const;

private:

	DynArray<List<Student>> lines;


};



#endif // !_CONGA_CONTAINER_
