#include <string>;
#include "PersonHandler.h"

using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int CAP = 3;

	PersonHandler person(CAP);

	person.add("Erik", "Erik.eli@live.se", "CivSpel");
	person.add("Erik2", "Erik.eli@live.se", "123123");
	person.add("teach", "Test@live.se", "nja", 10000);
	person.add("Eri3", "Erik.eli@live.se", "123123");

	const int nrofstudents = person.NrOfStudents();
	cout << nrofstudents;

	string array[10];
	person.allStudentAsString(array);

	for (int i = 0; i < nrofstudents;i++)
	{
		cout << array[i] << endl;
	}

	int nrofperson = person.getNrOfPerson();
	cout << nrofperson;
	person.tostring(array);
	for (int i = 0; i < nrofperson; i++)
	{
		cout << array[i] << endl;
	}

	PersonHandler person2(5);
	person2 = person;

	int nrofperson2 = person2.getNrOfPerson();
	cout << nrofperson2;
	person2.tostring(array);
	for (int i = 0; i < nrofperson2; i++)
	{
		cout << array[i] << endl;
	}

	system("pause");
	return 0;

	


}