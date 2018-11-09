#ifndef _STUDENT_
#define _STUDENT_



class Student
{

public:

	//Throws std::invalid_argument for unknown university.
	Student(const char* name, const char* universityName);
	Student(const Student &other);
	Student& operator=(const Student &other);
	~Student();

	bool IsCompatibleWith(const Student &other) const;


	void DebugPrint() const;
	void Print() const;

	const char* const GetName() const;

private:

	char* name;
	int universityCode;

	void Copy(const Student &other);
	void Clear();

};



#endif // !_STUDENT_
