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
	void tostring(string text[])const;  //utg�r ifr�n array har capacitet
	int NrOfStudents()const;
	void allStudentAsString(string text[])const;
};


// om en klass inneh�ller en rent virutell funktion blir klassen abstract och de inneb�r att att vi inte kan skapa
// n�gra objekt av denna typen

//nu m�ste subklasserna ha en egen definition av funktionen som �r rent virtuell i basklassen
#pragma once
