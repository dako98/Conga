#include <iostream>
#include "CongaContainer.h"
#include "Student.h"
#include "List.h"


int main()
{

	/*
	List<Student> test;
	List<Student> test2;

	test.PushBack(Student("Ivan", "FMI"));
	test.PushBack(Student("Ivan2", "UNSS"));
	test.PushBack(Student("Ivan3", "TU"));
//	test.PushBack(Student("Ivan4", "FMI2"));

	List<Student>::Iterator testIterator(test.begin());

	test2 = test.SplitAfter(testIterator);

	


	
	for(Student i : test)
	i.DebugPrint();

	std::cout << "------------------------------\n";

	for (Student i : test2)
		i.DebugPrint();

	std::cout << "------------------------------\n";

	CongaContainer containerTest;

	containerTest.AddPerson(0, "Ivan", "FMI");
	containerTest.AddPerson(0, "Ivan2", "UNSS");
	containerTest.AddPerson(0, "Ivan3", "UNSS");
	containerTest.AddPerson(0, "Ivan4", "TU");

//	containerTest.RemoveFirst(0);
//	containerTest.RemoveLast(0);
//	containerTest.AddPerson(0, "Ivan", "FMI");

	containerTest.Remove(0, "Ivan2");

	test.Append(test2);
	
	for (Student i : test)
		i.DebugPrint();

	std::cout << "------------------------------\n";


	containerTest.Print();
	*/


	CongaContainer test;

	test.AddPerson(0, "Ivan1", "FMI");
	test.AddPerson(0, "Ivan2", "UNSS");
	test.AddPerson(0, "Ivan3", "TU");
	test.AddPerson(0, "Ivan4", "FMI");
	test.AddPerson(0, "Ivan5", "FMI");

	test.Print();
	std::cout << "---------------------------\n";

	test.AddPerson(1, "Ivan1", "FMI");
	test.AddPerson(1, "Ivan2", "UNSS");
	test.AddPerson(1, "Ivan3", "TU");
	test.AddPerson(1, "Ivan4", "FMI");
	test.AddPerson(1, "Ivan5", "FMI");

	test.Print();
	std::cout << "---------------------------\n";


	test.RemoveLast(0);
	test.RemoveFirst(1);

	test.Print();
	std::cout << "---------------------------\n";



	test.Remove(0, "Ivan3");

	test.Print();
	std::cout << "---------------------------\n";



	test.Append(0, 1);

	test.Print();
	std::cout << "---------------------------\n";






	std::cout << "=================================\n";

	test.AddPerson(0, "pesho1", "unss");
	test.AddPerson(0, "pesho2", "unss");
	test.AddPerson(0, "pesho3", "tu");
	//test.AddPerson(0,"gatka","unss");
	test.Remove(0, "pesho1");
	//test.AddPerson(1,"gatka","tu");
	test.RemoveFirst(2);

	test.Append(1, 1);


	test.Print();


	system("pause");

	return 0;
}