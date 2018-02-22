#include "Employee.h"
#include "Student.h"
#include <iostream>

int main()
{
	/*Employee* test = new Employee("Eva", "test@test.test", "loled", 1337);
	cout << test->toString() << endl << endl;
	Person* test2 = new Employee("Britt", "b@BTH.se", "DIKR", 32000);
	cout << test2->toString() << endl << endl;
	Person* test3 = new Student("Erik", "Eler17@student.bth.se", "PAACI");
	cout << test3->toString() << endl << endl;
	/*cout << "OM EN FUNKTION �R �VERSKUGGAD(SAMMA PROTOTYP I BASKLASS OCH SLUTKLASS)" << endl;
	cout << "OCH FUNKTIONEN I BASKLASSEN �R VIRUTEL OCH PEKAR VARIABELN �R AV BASKLASSTYP" << endl;
	cout << "OCH OBJEKETET �R AV SUBKLASSTYP S� �R DET OBJEKTETS TYP SOM AVG�R VILKEN VERSION AV FUNKTIONEN SOM K�RS" << endl;



	//delete test;
	delete test2;
	delete test3;*/


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	int CAP = 5;
	int nrOfPersons = 0;
	Person* *persons = new Person*[CAP];
	
	persons[nrOfPersons++] = new Student("Pelle", "P@student.bth.se", "CivSpel");
	persons[nrOfPersons++] = new Student("Belle", "B@student.bth.se", "CivSpel");
	persons[nrOfPersons++] = new Employee("Britt", "Britt@bth.se","DIKR", 42000);
	persons[nrOfPersons++] = new Employee("Pritt", "Pritt@bth.se","DIRK", 31000);
	//skriver alla studenter och anst�llda
	for (int i=0; i< nrOfPersons;i++)
	{
		cout << persons[i]->toString() << endl;
	}

	//skriver endast studenter
	Student* studentPtr = nullptr;
	for (int i=0; i<nrOfPersons;i++)
	{
		studentPtr = dynamic_cast<Student*>(persons[i]);
		// om de inte g�r blir stduentPtr nullptr
		if(studentPtr != nullptr)
		{
			cout << persons[i]->toString() << endl;
		}
	}
	//skriver endast anst�llda som har en l�n �ver 33000kr
	Employee* employeePtr = nullptr;
	for (int i = 0; i<nrOfPersons; i++)
	{
		employeePtr = dynamic_cast<Employee*>(persons[i]);
		// om de inte g�r blir stduentPtr nullptr
		if (employeePtr != nullptr && employeePtr->getSalery() >33000)
		{
			cout << persons[i]->toString() << endl;
		}
	}
	for (int i = 0; i < nrOfPersons; i++) {
		delete persons[i];
	}
	delete[] persons;
	system("pause");
	return 0;
}