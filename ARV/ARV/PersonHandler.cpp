#include "PersonHandler.h"
#include "Student.h"
#include "Employee.h"

void PersonHandler::expand()
{
	this->capacity += 5;
	Person* *temp = new Person*[this->capacity];
	for (int i = 0; i < this->nrOfPersons; i++)
	{
		temp[i] = this->persons[i];
	}
	delete[] this->persons;
	this->persons = temp;
	this->initiate(this->nrOfPersons);
}
void PersonHandler::initiate(int from)
{
	for (int i = from; i<capacity; i++)
	{
		this->persons[i] = nullptr;
	}
}

PersonHandler::PersonHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfPersons = 0;
	this->persons = new Person*[this->capacity];
}

PersonHandler::PersonHandler(const PersonHandler & origObj)
{
	Student* studentPtr = nullptr;
	Employee* emplyeePtr = nullptr;


	//memberwise copy
	this->capacity = origObj.capacity;
	this->nrOfPersons = origObj.nrOfPersons;
	// deep copy regarding the array
	this->persons = new Person*[origObj.nrOfPersons];
	////deep copying regarding the objects
	//for (int i= 0; i < origObj.nrOfPersons; i++)
	//{
	//	studentPtr = dynamic_cast<Student*>(persons[i]);
	//	if (studentPtr != nullptr)
	//	{
	//		this->persons[i] = new Student(*studentPtr);
//
	//	}else
	//	{
	//		emplyeePtr = dynamic_cast<Employee*>(persons[i]);
	//		this->persons[i] = new Employee(*emplyeePtr);
	//	}
	//}

	for (int i = 0; i < origObj.nrOfPersons;i++)
	{
		this->persons[i] = origObj.persons[i]->clone();
	}

	initiate(this->nrOfPersons);
}

PersonHandler::~PersonHandler()
{
	for (int i = 0; i < this->nrOfPersons; i++)
	{
		delete this->persons[i];
	}
	delete[] this->persons;
}

PersonHandler & PersonHandler::operator=(const PersonHandler & origObj)
{
	for (int i = 0; i < this->nrOfPersons; i++)
	{
		delete this->persons[i];
	}
	delete[] this->persons;
	//this->makeCopy(origobj);
	Student* studentPtr = nullptr;
	Employee* emplyeePtr = nullptr;


	//memberwise copy
	this->capacity = origObj.capacity;
	this->nrOfPersons = origObj.nrOfPersons;
	// deep copy regarding the array
	this->persons = new Person*[this->capacity];
	//deep copying regarding the objects
	for (int i = 0; i < origObj.nrOfPersons; i++)
	{
		studentPtr = dynamic_cast<Student*>(origObj.persons[i]);
		if (studentPtr != nullptr)
		{
			this->persons[i] = new Student(*studentPtr);

		}
		else
		{
			emplyeePtr = dynamic_cast<Employee*>(origObj.persons[i]);
			this->persons[i] = new Employee(*emplyeePtr);
		}
	}

	initiate(this->nrOfPersons);
	return *this;

}

void PersonHandler::add(string name, string mail, string studyprogram)
{
		if (this->nrOfPersons == this->capacity)
		{
			this->expand();
		}

		this->persons[this->nrOfPersons] = new Student(name, mail,studyprogram); //derefererar pekare

		this->nrOfPersons++;
}

void PersonHandler::add(string name, string mail, string department, int salery)
{
	if (this->nrOfPersons == this->capacity)
	{
		this->expand();
	}

	this->persons[this->nrOfPersons] = new Employee(name, mail, department, salery); //derefererar pekare

	this->nrOfPersons++;
}

int PersonHandler::getNrOfPerson()const
{
	return this->nrOfPersons;
}

void PersonHandler::removePerson(string name, string mail)
{
	int pos = -1;
	for (int i = 0; i < this->nrOfPersons && pos == -1; i++)
	{
		if (this->persons[i]->getName() == name && this->persons[i]->getMail() == mail)
		{
			pos = i;
		}
	}

	if (pos != -1)
	{
		delete this->persons[pos];
		this->persons[pos] = this->persons[--this->nrOfPersons];
	}
}

void PersonHandler::tostring(string text[])const
{
	for (int i = 0; i < this->nrOfPersons; i++) {
		text[i] = persons[i]->toString();
	}
}

int PersonHandler::NrOfStudents()const
{
	Student* studentPtr = nullptr;
	int nrOfStudents = 0;

	for (int i = 0; i < nrOfPersons; i++)
	{
		studentPtr = dynamic_cast<Student*>(persons[i]);
		// om de inte går blir stduentPtr nullptr
		if (studentPtr != nullptr)
		{
			nrOfStudents++;
		}
	}
	return nrOfStudents;

}

void PersonHandler::allStudentAsString(string text[])const
{
	Student* studentPtr = nullptr;
	int j = 0;
	for (int i = 0; i < nrOfPersons; i++)
	{
		studentPtr = dynamic_cast<Student*>(persons[i]);
		if (studentPtr != nullptr)
		{
			text[j++] = this->persons[i]->toString();
		}
	}
}