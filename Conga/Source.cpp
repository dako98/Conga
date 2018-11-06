#include <iostream>
#include "CongaContainer.h"
#include "Student.h"
#include "List.h"


int main()
{

	List<Student> test;
	test.PushBack(Student("Ivan", "FMI"));
	test.PushBack(Student("Ivan2", "UNSS"));
	test.PushBack(Student("Ivan3", "TU"));
//	test.PushBack(Student("Ivan4", "FMI2"));


	List<Student>::Iterator testIterator(test.begin());
	
	for(Student i : test)
	i.DebugPrint();

	std::cout << "------------------------------\n";

	CongaContainer containerTest;

	containerTest.AddPerson(0, "Ivan", "FMI");
	containerTest.AddPerson(0, "Ivan2", "UNSS");
	containerTest.AddPerson(0, "Ivan3", "UNSS");
	containerTest.AddPerson(0, "Ivan4", "TU");

	containerTest.RemoveFirst(0);
	containerTest.RemoveLast(0);
	containerTest.AddPerson(0, "Ivan", "FMI");


	containerTest.DebugPrint();

	return 0;
}