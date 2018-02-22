#pragma once
#include <string>
#include <iostream>
#include "Person.h"


using namespace std;

class PersonHandler
{

private:
	Person * *persons;
	int capacity;
	int nrOfPersons;
	void expand();
	void initiate(int from = 0);

public:
	PersonHandler(int capacity);
	PersonHandler(const PersonHandler& origObj);
	virtual~PersonHandler();
	PersonHandler& operator=(const PersonHandler& origObj);
	void add(string name, string mail, string studyprogram);
	void add(string name, string mail, string department, int salery);
	int getNrOfPerson()const;
	void removePerson(string name, string mail);
	void tostring(string text[])const;  //utgår ifrån array har capacitet
	int NrOfStudents()const;
	void allStudentAsString(string text[])const;
};


// om en klass innehåller en rent virutell funktion blir klassen abstract och de innebär att att vi inte kan skapa
// några objekt av denna typen

//nu måste subklasserna ha en egen definition av funktionen som är rent virtuell i basklassen
#pragma once
