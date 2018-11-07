#ifndef _UNIVERSITY_IDS_
#define _UNIVERSITY_IDS_

//USE EXTERN!

enum UniversityCodes
{
	INVALID = -1,

	FMI,
	UNSS,
	TU,

	UNIVERSITYS_COUNT
};

//Must be in same order with UniversityCodes
const char* UNIVERSITY_NAMES[] = {
	"FMI",
	"UNSS",
	"TU"
};

//This supports friendships up to the number of universities.
//The last element must always be INVALID.
const int UNIVERSITY_FRIENDSHIPS[UNIVERSITYS_COUNT][UNIVERSITYS_COUNT + 1] = {
	{FMI, TU, INVALID},
	{UNSS, FMI, INVALID},
	{TU, UNSS, INVALID}
};




#endif // !_UNIVERSITY_IDS_