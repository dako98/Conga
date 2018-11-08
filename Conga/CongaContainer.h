#ifndef _CONGA_CONTAINER_
#define _CONGA_CONTAINER_

#include "List.h"
#include "DynamicArray.h"
#include "Student.h"

class CongaContainer
{

public:

	CongaContainer();


	void AddPerson(int lineID, const char* personName,
		const char* universityName);

	void RemoveLast(int lineID);
	void RemoveFirst(int lineID);

	void Print() const;

	void Remove(int lineID, const char* name);
	void Append(int line1, int line2);

	void DebugPrint() const;

private:

//	int linesCount;

	//Use dynamic array!
//	List<Student>* lines;

	DynArray<List<Student>> lines;


};



#endif // !_CONGA_CONTAINER_
