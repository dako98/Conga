#ifndef _CONGA_CONTAINER_
#define _CONGA_CONTAINER_

#include "List.h"
#include "Student.h"

class CongaContainer
{

public:

	CongaContainer();


	void AddPerson(int lineID, const char* personName, const char* universityName);


private:

	int linesCount;

	//Use dynamic array!
	List<Student>* lines;

};



#endif // !_CONGA_CONTAINER_
