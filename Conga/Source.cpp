#include <iostream>
#include "Conga.h"
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


	return 0;
}